//
//  OpenCVConstants.h
//  OpenCVTry
//
//  Created by Kohei Arai on 10/4/14.
//  Copyright (c) 2014 Kohei Arai. All rights reserved.
//

#ifndef OpenCVTry_OpenCVConstants_h
#define OpenCVTry_OpenCVConstants_h

#define CV_BLUR_NO_SCALE 0
#define CV_BLUR  1
#define CV_GAUSSIAN  2
#define CV_MEDIAN 3
#define CV_BILATERAL 4
#define CV_INPAINT_NS      0
#define CV_INPAINT_TELEA   1
#define CV_SCHARR -1
#define CV_MAX_SOBEL_KSIZE 7
#define  CV_BGR2BGRA    0
#define  CV_RGB2RGBA    CV_BGR2BGRA
#define  CV_BGRA2BGR    1
#define  CV_RGBA2RGB    CV_BGRA2BGR
#define  CV_BGR2RGBA    2
#define  CV_RGB2BGRA    CV_BGR2RGBA
#define  CV_RGBA2BGR    3
#define  CV_BGRA2RGB    CV_RGBA2BGR
#define  CV_BGR2RGB     4
#define  CV_RGB2BGR     CV_BGR2RGB
#define  CV_BGRA2RGBA   5
#define  CV_RGBA2BGRA   CV_BGRA2RGBA
#define  CV_BGR2GRAY    6
#define  CV_RGB2GRAY    7
#define  CV_GRAY2BGR    8
#define  CV_GRAY2RGB    CV_GRAY2BGR
#define  CV_GRAY2BGRA   9
#define  CV_GRAY2RGBA   CV_GRAY2BGRA
#define  CV_BGRA2GRAY   10
#define  CV_RGBA2GRAY   11
#define  CV_BGR2BGR565  12
#define  CV_RGB2BGR565  13
#define  CV_BGR5652BGR  14
#define  CV_BGR5652RGB  15
#define  CV_BGRA2BGR565 16
#define  CV_RGBA2BGR565 17
#define  CV_BGR5652BGRA 18
#define  CV_BGR5652RGBA 19
#define  CV_GRAY2BGR565 20
#define  CV_BGR5652GRAY 21
#define  CV_BGR2BGR555  22
#define  CV_RGB2BGR555  23
#define  CV_BGR5552BGR  24
#define  CV_BGR5552RGB  25
#define  CV_BGRA2BGR555 26
#define  CV_RGBA2BGR555 27
#define  CV_BGR5552BGRA 28
#define  CV_BGR5552RGBA 29
#define  CV_GRAY2BGR555 30
#define  CV_BGR5552GRAY 31
#define  CV_BGR2XYZ     32
#define  CV_RGB2XYZ     33
#define  CV_XYZ2BGR     34
#define  CV_XYZ2RGB     35
#define  CV_BGR2YCrCb   36
#define  CV_RGB2YCrCb   37
#define  CV_YCrCb2BGR   38
#define  CV_YCrCb2RGB   39
#define  CV_BGR2HSV     40
#define  CV_RGB2HSV     41
#define  CV_BGR2Lab     44
#define  CV_RGB2Lab     45
#define  CV_BayerBG2BGR 46
#define  CV_BayerGB2BGR 47
#define  CV_BayerRG2BGR 48
#define  CV_BayerGR2BGR 49
#define  CV_BayerBG2RGB CV_BayerRG2BGR
#define  CV_BayerGB2RGB CV_BayerGR2BGR
#define  CV_BayerRG2RGB CV_BayerBG2BGR
#define  CV_BayerGR2RGB CV_BayerGB2BGR
#define  CV_BayerBG2BGR_VNG 62
#define  CV_BayerGB2BGR_VNG 63
#define  CV_BayerRG2BGR_VNG 64
#define  CV_BayerGR2BGR_VNG 65
#define  CV_BGR2Luv     50
#define  CV_RGB2Luv     51
#define  CV_BGR2HLS     52
#define  CV_RGB2HLS     53
#define  CV_HSV2BGR     54
#define  CV_HSV2RGB     55
#define  CV_Lab2BGR     56
#define  CV_Lab2RGB     57
#define  CV_Luv2BGR     58
#define  CV_Luv2RGB     59
#define  CV_HLS2BGR     60
#define  CV_HLS2RGB     61
#define  CV_COLORCVT_MAX  100
#define  CV_INTER_NN        0
#define  CV_INTER_LINEAR    1
#define  CV_INTER_CUBIC     2
#define  CV_INTER_AREA      3
#define  CV_WARP_FILL_OUTLIERS 8
#define  CV_WARP_INVERSE_MAP  16
#define  CV_SHAPE_RECT      0
#define  CV_SHAPE_CROSS     1
#define  CV_SHAPE_ELLIPSE   2
#define  CV_SHAPE_CUSTOM    100
#define CV_MOP_OPEN         2
#define CV_MOP_CLOSE        3
#define CV_MOP_GRADIENT     4
#define CV_MOP_TOPHAT       5
#define CV_MOP_BLACKHAT     6
#define  CV_TM_SQDIFF        0
#define  CV_TM_SQDIFF_NORMED 1
#define  CV_TM_CCORR         2
#define  CV_TM_CCORR_NORMED  3
#define  CV_TM_CCOEFF        4
#define  CV_TM_CCOEFF_NORMED 5
#define  CV_LKFLOW_PYR_A_READY       1
#define  CV_LKFLOW_PYR_B_READY       2
#define  CV_LKFLOW_INITIAL_GUESSES   4
#define  CV_LKFLOW_GET_MIN_EIGENVALS 8
#define CV_POLY_APPROX_DP 0
#define CV_CONTOURS_MATCH_I1  1
#define CV_CONTOURS_MATCH_I2  2
#define CV_CONTOURS_MATCH_I3  3
#define CV_CLOCKWISE         1
#define CV_COUNTER_CLOCKWISE 2
#define CV_COMP_CORREL        0
#define CV_COMP_CHISQR        1
#define CV_COMP_INTERSECT     2
#define CV_COMP_BHATTACHARYYA 3
#define CV_DIST_MASK_3   3
#define CV_DIST_MASK_5   5
#define CV_DIST_MASK_PRECISE 0
#define CV_THRESH_BINARY      0  /* value = value > threshold ? max_value : 0       */
#define CV_THRESH_BINARY_INV  1  /* value = value > threshold ? 0 : max_value       */
#define CV_THRESH_TRUNC       2  /* value = value > threshold ? threshold : value   */
#define CV_THRESH_TOZERO      3  /* value = value > threshold ? value : 0           */
#define CV_THRESH_TOZERO_INV  4  /* value = value > threshold ? 0 : value           */
#define CV_THRESH_MASK        7
#define CV_THRESH_OTSU        8  /* use Otsu algorithm to choose the optimal threshold value;
#define CV_ADAPTIVE_THRESH_MEAN_C  0
#define CV_ADAPTIVE_THRESH_GAUSSIAN_C  1
#define CV_FLOODFILL_FIXED_RANGE (1 << 16)
#define CV_FLOODFILL_MASK_ONLY   (1 << 17)
#define CV_CANNY_L2_GRADIENT  (1 << 31)
#define CV_HOUGH_STANDARD 0
#define CV_HOUGH_PROBABILISTIC 1
#define CV_HOUGH_MULTI_SCALE 2
#define CV_HOUGH_GRADIENT 3
#define CV_HAAR_DO_CANNY_PRUNING    1
#define CV_HAAR_SCALE_IMAGE         2
#define CV_HAAR_FIND_BIGGEST_OBJECT 4
#define CV_HAAR_DO_ROUGH_SEARCH     8
#define CV_LMEDS 4
#define CV_RANSAC 8
#define CV_CALIB_CB_ADAPTIVE_THRESH  1
#define CV_CALIB_CB_NORMALIZE_IMAGE  2
#define CV_CALIB_CB_FILTER_QUADS     4
#define CV_CALIB_USE_INTRINSIC_GUESS  1
#define CV_CALIB_FIX_ASPECT_RATIO     2
#define CV_CALIB_FIX_PRINCIPAL_POINT  4
#define CV_CALIB_ZERO_TANGENT_DIST    8
#define CV_CALIB_FIX_FOCAL_LENGTH 16
#define CV_CALIB_FIX_K1  32
#define CV_CALIB_FIX_K2  64
#define CV_CALIB_FIX_K3  128
#define CV_CALIB_FIX_INTRINSIC  256
#define CV_CALIB_SAME_FOCAL_LENGTH 512
#define CV_CALIB_ZERO_DISPARITY 1024
#define CV_FM_7POINT 1
#define CV_FM_8POINT 2
#define CV_FM_LMEDS_ONLY  CV_LMEDS
#define CV_FM_RANSAC_ONLY CV_RANSAC
#define CV_FM_LMEDS CV_LMEDS
#define CV_FM_RANSAC CV_RANSAC
#define CV_STEREO_BM_NORMALIZED_RESPONSE  0
#define CV_STEREO_BM_BASIC 0
#define CV_STEREO_BM_FISH_EYE 1
#define CV_STEREO_BM_NARROW 2
#define CV_STEREO_GC_OCCLUDED  SHRT_MAX
#define CV_AUTOSTEP  0x7fffffff
#define CV_MAX_ARR 10
#define CV_NO_DEPTH_CHECK     1
#define CV_NO_CN_CHECK        2
#define CV_NO_SIZE_CHECK      4
#define CV_CMP_EQ   0
#define CV_CMP_GT   1
#define CV_CMP_GE   2
#define CV_CMP_LT   3
#define CV_CMP_LE   4
#define CV_CMP_NE   5
#define  CV_CHECK_RANGE    1
#define  CV_CHECK_QUIET    2
#define CV_RAND_UNI      0
#define CV_RAND_NORMAL   1
#define CV_SORT_EVERY_ROW 0
#define CV_SORT_EVERY_COLUMN 1
#define CV_SORT_ASCENDING 0
#define CV_SORT_DESCENDING 16
#define CV_GEMM_A_T 1
#define CV_GEMM_B_T 2
#define CV_GEMM_C_T 4
#define CV_SVD_MODIFY_A   1
#define CV_SVD_U_T        2
#define CV_SVD_V_T        4
#define CV_LU  0
#define CV_SVD 1
#define CV_SVD_SYM 2
#define CV_CHOLESKY 3
#define CV_QR  4
#define CV_NORMAL 16
#define CV_COVAR_SCRAMBLED 0
#define CV_COVAR_NORMAL    1
#define CV_COVAR_USE_AVG   2
#define CV_COVAR_SCALE     4
#define CV_COVAR_ROWS      8
#define CV_COVAR_COLS     16
#define CV_PCA_DATA_AS_ROW 0
#define CV_PCA_DATA_AS_COL 1
#define CV_PCA_USE_AVG 2
#define CV_C            1
#define CV_L1           2
#define CV_L2           4
#define CV_NORM_MASK    7
#define CV_RELATIVE     8
#define CV_DIFF         16
#define CV_MINMAX       32
#define CV_DIFF_C       (CV_DIFF | CV_C)
#define CV_DIFF_L1      (CV_DIFF | CV_L1)
#define CV_DIFF_L2      (CV_DIFF | CV_L2)
#define CV_RELATIVE_C   (CV_RELATIVE | CV_C)
#define CV_RELATIVE_L1  (CV_RELATIVE | CV_L1)
#define CV_RELATIVE_L2  (CV_RELATIVE | CV_L2)
#define CV_REDUCE_SUM 0
#define CV_REDUCE_AVG 1
#define CV_REDUCE_MAX 2
#define CV_REDUCE_MIN 3
#define CV_DXT_FORWARD  0
#define CV_DXT_INVERSE  1
#define CV_DXT_SCALE    2 /* divide result by size of array */
#define CV_DXT_INV_SCALE (CV_DXT_INVERSE + CV_DXT_SCALE)
#define CV_DXT_INVERSE_SCALE CV_DXT_INV_SCALE
#define CV_DXT_ROWS     4 /* transform each row individually */
#define CV_DXT_MUL_CONJ 8 /* conjugate the second argument of cvMulSpectrums */
#define CV_FRONT 1
#define CV_BACK 0
#define  CV_GRAPH_VERTEX        1
#define  CV_GRAPH_TREE_EDGE     2
#define  CV_GRAPH_BACK_EDGE     4
#define  CV_GRAPH_FORWARD_EDGE  8
#define  CV_GRAPH_CROSS_EDGE    16
#define  CV_GRAPH_ANY_EDGE      30
#define  CV_GRAPH_NEW_TREE      32
#define  CV_GRAPH_BACKTRACKING  64
#define  CV_GRAPH_OVER          -1
#define  CV_GRAPH_ALL_ITEMS    -1
#define  CV_GRAPH_ITEM_VISITED_FLAG  (1 << 30)
#define  CV_GRAPH_SEARCH_TREE_NODE_FLAG   (1 << 29)
#define  CV_GRAPH_FORWARD_EDGE_FLAG       (1 << 28)
#define CV_FILLED -1
#define CV_AA 16
#define CV_FONT_HERSHEY_SIMPLEX         0
#define CV_FONT_HERSHEY_PLAIN           1
#define CV_FONT_HERSHEY_DUPLEX          2
#define CV_FONT_HERSHEY_COMPLEX         3
#define CV_FONT_HERSHEY_TRIPLEX         4
#define CV_FONT_HERSHEY_COMPLEX_SMALL   5
#define CV_FONT_HERSHEY_SCRIPT_SIMPLEX  6
#define CV_FONT_HERSHEY_SCRIPT_COMPLEX  7
#define CV_FONT_ITALIC                 16
#define CV_FONT_VECTOR0    CV_FONT_HERSHEY_SIMPLEX
#define CV_KMEANS_USE_INITIAL_LABELS    1
#define CV_ErrModeLeaf     0   /* Print error and exit program */
#define CV_ErrModeParent   1   /* Print error and continue */
#define CV_ErrModeSilent   2   /* Don't print and continue */
#define CV_RETR_EXTERNAL 0
#define CV_RETR_LIST     1
#define CV_RETR_CCOMP    2
#define CV_RETR_TREE     3
#define CV_CHAIN_CODE               0
#define CV_CHAIN_APPROX_NONE        1
#define CV_CHAIN_APPROX_SIMPLE      2
#define CV_CHAIN_APPROX_TC89_L1     3
#define CV_CHAIN_APPROX_TC89_KCOS   4
#define CV_LINK_RUNS                5
#define CV_SUBDIV2D_VIRTUAL_POINT_FLAG (1 << 30)
#define CV_DIST_USER    -1  /* User defined distance */
#define CV_DIST_L1      1   /* distance = |x1-x2| + |y1-y2| */
#define CV_DIST_L2      2   /* the simple euclidean distance */
#define CV_DIST_C       3   /* distance = max(|x1-x2|,|y1-y2|) */
#define CV_DIST_L12     4   /* L1-L2 metric: distance = 2(sqrt(1+x*x/2) - 1)) */
#define CV_DIST_FAIR    5   /* distance = c^2(|x|/c-log(1+|x|/c)), c = 1.3998 */
#define CV_DIST_WELSCH  6   /* distance = c^2/2(1-exp(-(x/c)^2)), c = 2.9846 */
#define CV_DIST_HUBER   7   /* distance = |x|<c ? x^2/2 : c(|x|-c/2), c=1.345 */
#define CV_HAAR_MAGIC_VAL    0x42500000
#define CV_HAAR_FEATURE_MAX  3
#define CV_TERMCRIT_ITER    1
#define CV_TERMCRIT_NUMBER  CV_TERMCRIT_ITER
#define CV_TERMCRIT_EPS     2
#define CV_EVENT_MOUSEMOVE      0
#define CV_EVENT_LBUTTONDOWN    1
#define CV_EVENT_RBUTTONDOWN    2
#define CV_EVENT_MBUTTONDOWN    3
#define CV_EVENT_LBUTTONUP      4
#define CV_EVENT_RBUTTONUP      5
#define CV_EVENT_MBUTTONUP      6
#define CV_EVENT_LBUTTONDBLCLK  7
#define CV_EVENT_RBUTTONDBLCLK  8
#define CV_EVENT_MBUTTONDBLCLK  9
#define CV_EVENT_FLAG_LBUTTON   1
#define CV_EVENT_FLAG_RBUTTON   2
#define CV_EVENT_FLAG_MBUTTON   4
#define CV_EVENT_FLAG_CTRLKEY   8
#define CV_EVENT_FLAG_SHIFTKEY  16
#define CV_EVENT_FLAG_ALTKEY    32
#define CV_MAX_DIM            32
#define CV_CAP_PROP_POS_MSEC       0
#define CV_CAP_PROP_POS_FRAMES     1
#define CV_CAP_PROP_POS_AVI_RATIO  2
#define CV_CAP_PROP_FRAME_WIDTH    3
#define CV_CAP_PROP_FRAME_HEIGHT   4
#define CV_CAP_PROP_FPS            5
#define CV_CAP_PROP_FOURCC         6
#define CV_CAP_PROP_FRAME_COUNT    7
#define CV_CAP_PROP_FORMAT         8
#define CV_CAP_PROP_MODE           9
#define CV_CAP_PROP_BRIGHTNESS    10
#define CV_CAP_PROP_CONTRAST      11
#define CV_CAP_PROP_SATURATION    12
#define CV_CAP_PROP_HUE           13
#define CV_CAP_PROP_GAIN          14
#define CV_CAP_PROP_EXPOSURE      15
#define CV_CAP_PROP_CONVERT_RGB   16
#define CV_CAP_PROP_RECTIFICATION 18
#define CV_CN_SHIFT   3
#define CV_IMWRITE_JPEG_QUALITY 1
#define CV_IMWRITE_PNG_COMPRESSION 16
#define CV_IMWRITE_PXM_BINARY 32
#define IPL_ORIGIN_TL 0
#define IPL_ORIGIN_BL 1
#define CV_GAUSSIAN_5x5
#define CV_CN_MAX
#define CV_WINDOW_AUTOSIZE  1
#define CV_WINDOW_NORMAL	 	 0
#define CV_WINDOW_FULLSCREEN	 1
#define HG_AUTOSIZE CV_WINDOW_AUTOSIZE
#define CV_CVTIMG_FLIP  1
#define CV_CVTIMG_SWAP_RB 2
#endif
