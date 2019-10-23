vector<Point> bhContoursCenter(const vector<vector<Point>>& contours,bool centerOfMass,int contourIdx=-1)
{
    vector<Point> result;
    if (contourIdx > -1)
    {
        if (centerOfMass)
        {
            Moments m = moments(contours[contourIdx],true);
            result.push_back( Point(m.m10/m.m00, m.m01/m.m00));
        }
        else
        {
            Rect rct = boundingRect(contours[contourIdx]);
            result.push_back( Point(rct.x + rct.width / 2 ,rct.y + rct.height / 2));
        }
    }
    else
    {
        if (centerOfMass)
        {
            for (int i=0; i < contours.size();i++)
            {
                Moments m = moments(contours[i],true);
                result.push_back( Point(m.m10/m.m00, m.m01/m.m00));

            }
        }
        else
        {

            for (int i=0; i < contours.size(); i++)
            {
                Rect rct = boundingRect(contours[i]);
                result.push_back(Point(rct.x + rct.width / 2 ,rct.y + rct.height / 2));
            }
        }
    }

    return result;
}


    vector<Point> bhFindLocalMaximum(InputArray _src,int neighbor=2){
        Mat src = _src.getMat();

        Mat peak_img = src.clone();
        dilate(peak_img,peak_img,Mat(),Point(-1,-1),neighbor);
        peak_img = peak_img - src;



        Mat flat_img ;
        erode(src,flat_img,Mat(),Point(-1,-1),neighbor);
        flat_img = src - flat_img;


        threshold(peak_img,peak_img,0,255,CV_THRESH_BINARY);
        threshold(flat_img,flat_img,0,255,CV_THRESH_BINARY);
        bitwise_not(flat_img,flat_img);

        peak_img.setTo(Scalar::all(255),flat_img);
        bitwise_not(peak_img,peak_img);


        vector<vector<Point>> contours;
        findContours(peak_img,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);

        return bhContoursCenter(contours,true);
    }

    typedef struct  BhRange
        {
            int pos1;
            int pos2;
            int size()
            {
                return pos2 - pos1 +1;
            }
        }BhRange;
        typedef struct  BhPeekInfo
        {
            int pos;
            int left_size;
            int right_size;
            float value;
        }BhPeekInfo;

        typedef vector<BhPeekInfo>  BhPeekInfos;
        BhPeekInfo bhPeekInfo(int pos,int left_size,int
    right_size,float value)
        {
            BhPeekInfo result;
            result.pos = pos;
            result.left_size = left_size;
            result.right_size = right_size;
            result.value = value;
            return result;
        }
        BhPeekInfos bhFindPeeks2(InputArray _src,int
    window_size)
        {
            Mat src = _src.getMat();
            //#define _BH_SHOW_IMAGE

        #ifdef _BH_SHOW_IMAGE
            CvMat *slope_mat = cvCloneMat(src);
            float *slope_p = slope_mat->data.fl;
        #endif
            Mat src2 = src.reshape(1,1);

            float *src_p = (float*) src2.ptr<float>(0);

            int size = window_size / 2;
            int thr = 20;

            BhRange up_hill ,down_hill;
            BhPeekInfos result;

            int pre_state = 0;
            int i = size;
            while ( i < src2.cols - size)
            {
                float cur_state =  src_p[i + size] - src_p[i - size];

                if (cur_state > 0)
                    cur_state = 2;
                else if (cur_state < 0)
                    cur_state = 1;
                else  cur_state = 0;

        #ifdef _BH_SHOW_IMAGE
                slope_p[i] = cur_state;
        #endif
                if (pre_state == 0 && cur_state == 2)
                    up_hill.pos1 = i;
                else if (pre_state == 2 && cur_state == 1)
                {
                    up_hill.pos2 = i -1;
                    down_hill.pos1 = i;
                }
                if ((pre_state == 1 && cur_state == 2) || (pre_state == 1
    && cur_state == 0))
                {
                    down_hill.pos2 = i-1;
                    int max_pos = up_hill.pos2;
                    if ( src_p[up_hill.pos2] < src_p[down_hill.pos1])
                        max_pos = down_hill.pos1;

                    BhPeekInfo peek_info = bhPeekInfo(max_pos,up_hill.size(),down_hill.size(),src_p[max_pos]);
                    result.push_back(peek_info);
                }
                i++;
                pre_state = (int)cur_state;
            }

        #ifdef _BH_SHOW_IMAGE
            IplImage *view_img = bhDrawProjection(slope_mat,BH_HORZ_DIRECT,100,BH_DRAW_BAR);
            cvShowImage("slope image",view_img);
            cvWaitKey(0);
            cvReleaseImage(&view_img);
            cvReleaseMat(&slope_mat);
        #undef _BH_SHOW_IMAGE
        #endif

            return result;
        }


        vector<int> bhGetLocalMaximum2(InputArray
    _src,int smooth_size =9,int neighbor_size =3,float peek_per=0.5)
        {
            Mat src = _src.getMat().clone();
            //#define _BH_SHOW_IMAGE
        #ifdef _BH_DEBUG
        #define _BH_SHOW_IMAGE
        #endif
            vector<int> result;
            GaussianBlur(src,src,Size(smooth_size,smooth_size),0);

            BhPeekInfos peeks = bhFindPeeks2(src,neighbor_size);

            double min_val,max_val;
            minMaxLoc(src,&min_val,&max_val);

            for (size_t i=0; i < peeks.size();i++)
                if (peeks[i].value > max_val * peek_per && peeks[i].left_size >= 2
    && peeks[i].right_size >= 2)
                    result.push_back(peeks[i].pos);

        #ifdef _BH_SHOW_IMAGE
            Mat view_img ;
            bhDrawProjection(src,view_img,BH_HORZ_DIRECT,100,BH_DRAW_BAR,BH_WHITE,BH_BLACK,1,true);
            for (int i=0; i < result.size();i++)
                bhDrawVertLine(view_img,result[i],BH_GRAY,1);

            imshow("view_img",view_img);
            waitKey(0);


            //cvReleaseImage(&view_img);

        #endif

            //cvReleaseMat(&src);

            return result;


        }
