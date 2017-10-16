//
//  PiEnumTypes.h
//  Unity-iPhone
//
//  Created by forest on 2017/5/18.
//
//

#ifndef PiEnumTypes_h
#define PiEnumTypes_h

typedef NS_OPTIONS(NSInteger, PIErrCode)
{
    PI_SUCCESS = 0,                         // 成功
    PI_UNKNOWN_ERROR = -1,                  // 未知错误
    PI_UNITY_INIT_FAILED = -1000,           // unity初始化失败
    PI_UNITY_INSTANTIATION_FAILED = -1001,  // unity实例化失败
    PI_DRIVER_INIT_FAILED = -1300,          // 设备初始化失败
    
    PI_START_VIDEO_FAILED = 1,              //启动视频流失败
    
    PI_AlreadyStartPreview,                 //已经开始预览
    PI_AlreadyStopPreview,                  //已经结束预览
    
    PI_NotInPreview,                        //没有在预览中
    
};


/**
 图像输入源模式
 */
typedef NS_OPTIONS(NSInteger, PiSourceMode)
{
    PISM_OneEye,                            //单鱼眼
    PISM_TwoEye,                            //双鱼眼
    PISM_Full21                             //全景2:1展开图
};


/**
 单鱼眼镜头朝向
 需要设置这个朝向可以让单鱼眼镜头想要在VR和沉浸模式下有良好的表现，否则可能出现黑边。
 */
typedef NS_OPTIONS(NSInteger, PiCameraDirection)
{
    PICD_Up,                                //向上
    PICD_Down,                              //向下
    PICD_Front                              //水平
};

/**
 展开模式
 */
typedef NS_OPTIONS(NSInteger, PiViewMode)
{
    //basic
    PIVM_Immerse = 0,                       //沉浸
    PIVM_FishEye,                           //鱼眼
    PIVM_Asteroid,                          //小行星
    PIVM_VR,                                //VR分屏
    PIVM_Raw,                               //原始
    
    //Extended
    PIVM_Plane,                             //平铺
    PIVM_TwoScroll,                         //双画卷
    PIVM_FourSplit,                         //四分屏
    PIVM_Cylinder,                          //圆柱
    
    //Custom
    PIVM_PolarPlane,                        //极坐标平铺
    PIVM_PolarCylinder,                     //极坐标圆柱
    PIVM_Nav,                               //导航
    PIVM_Mix,                               //综合
    PIVM_FallIn,                            //坠入
    PIVM_WideAngle,                         //广角
    PIVM_CylinderPlane,                     //圆柱平铺
    PIVM_Max,                               //无模式，仅代表最大数
};


/**
 转场动画，付费版才有。
 */
typedef NS_OPTIONS(NSInteger, PiTransitionEffect)
{
    PITE_None = -1,                         //无
    PITE_Shake = 0,                         //震动
    PITE_Cube,                              //立体翻转
    PITE_Fade,                              //渐变
    PITE_Flip,                              //翻转
    PITE_Fold,                              //折叠
    PITE_Gate,                              //开门
    PITE_Page,                              //翻页
    PITE_Radial,                            //雷达
    PITE_Circle,                            //光圈
    PITE_Line,                              //划变
    PITE_Swap,                              //交换
    PITE_Wave,                              //波浪
    PITE_Max,                               //
};

/**
 滤镜，付费版才有。
 */
typedef NS_OPTIONS(NSInteger, PiFilterMode)
{
    PIFM_None = -1,
    
    PIFM_Bleach = 0,                        //锐化
    PIFM_Charcoal,                          //木炭笔
    PIFM_Contours,                          //轮廓
    PIFM_Desaturate,                        //老照片
    PIFM_Emboss,                            //浮雕
//    PIFM_Godrays,                           //上帝之光
    PIFM_Pixelated,                         //像素化
    PIFM_Posterize,                         //海报
    PIFM_Vintage,                           //暖色
    PIFM_Blueberry,                         //蓝莓
    PIFM_Amethyst,                          //紫晶
    
    PIFM_Max,
};


#endif /* PiEnumTypes_h */
