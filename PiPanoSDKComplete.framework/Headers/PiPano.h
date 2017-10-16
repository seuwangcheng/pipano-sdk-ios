//
//  PiPanoSDK.h
//  Unity-iPhone
//
//  Created by forest on 2017/5/18.
//
//

#ifndef PiPano_h
#define PiPano_h

#import "PiEnumTypes.h"
#include "PiDefines.h"

@interface PiPano : NSObject

/**
 PiPano SDK已经准备好的block。当PiPano SDK准备好时，会调用这个block。

 @param onReady 接收事件的block
 */
+(void) onPiPanoSDKReady:(PiPanoSDKReadyBlock)onReady;

/**
 当不使用PICamera720解码时，设置已经解码过的视频流的一帧。请在获取到视频流后调用这个方法，每一帧都要调用。
 
 @param videoFrame 视频流中的一帧。确保视频的 kCVPixelBufferPixelFormatTypeKey 设置为 kCVPixelFormatType_420YpCbCr8BiPlanarFullRange
 */
+(void) setVideoStreamFrame: (CVPixelBufferRef)videoFrame;


/**
 设置输入源图像模式。目前支持三种输入源：单鱼眼，双鱼眼，全景2:1展开图

 @param sourceMode 输入源图像模式
 */
+(void) setSourceMode: (PiSourceMode)sourceMode;


/**
 设置单鱼眼镜头朝向
 需要设置这个朝向可以让单鱼眼镜头想要在VR和沉浸模式下有良好的表现，否则可能出现黑边。

 @param cameraDir 朝向
 */
+(void) setOneEyeCameraDirection: (PiCameraDirection)cameraDir;

/**
 获取展开模式的名字

 @param showMode 展开模式
 @return 模式名
 */
+ (NSString*)viewModeName:(PiViewMode)showMode;



/**
 获取镜头视图

 @return 镜头视图
 */
+(UIView*) getCameraView;


/**
 开始预览相机

 @return 成功返回SUCCESS，失败返回错误码。
 */
+(PIErrCode) startPreview: (PiSourceMode) sourceMode;

/**
 停止预览相机

 @return 成功返回SUCCESS，失败返回错误码。
 */
+(PIErrCode) stopPreview;

/**
 当前是否在预览状态中

 @return 
 */
+(BOOL) isInPreview;



/**
 设置屏幕的朝向

 @param mode 正向竖屏："1",倒向竖屏："2",左向横屏："3",右向横屏："4",随感应器自动确定方向："5",
 */
+(void) setScreenOrientation: (NSString*)mode;



/**
 设置预览模式

 @param mode 预览模式
 @return 是否设置成功。如果失败，说明当前输入源图像不支持mode预览模式。
 */
+(BOOL) setViewMode: (PiViewMode)mode;

/**
 获取当前预览模式

 @return PiViewMode
 */
+(PiViewMode) getViewMode;


/**
打开图片
 */
+(void) openPhoto:(NSString*)photoPath  sourceMode : (PiSourceMode) sourceMode;

/**
 打开视频
 */
+(void) openVideo:(NSString*)videoPath sourceMode : (PiSourceMode) sourceMode;
/**
停止视频
 */
+(void) stopVideo;

/**
 暂停视频
 */
+(void) pauseVideo;

/**
 回复播放视频
 */
+(void) resumeVideo;

/**
 设置视频进度
 
 @param offset 进度 0-1之间。
 */
+(void) seekVideo: (float)offset;


/**
 获取当前视频的播放进度。因为PICamera720SDK不能立即得到播放进度，所以需要block来获取。
 */
+(void)getVideoProcess:(PiGetVideoProcessBlock)getProcessBlock;




/**
 设置转场动画

 @param effect 转场动画
 */
+(void) setTransitionEffect: (PiTransitionEffect)effect;

/**
 获取过场动画的名称

 @param effect 过场动画
 @return 动画的名称
 */
+ (NSString*)transitionEffectName:(PiTransitionEffect)effect;



/**
 设置滤镜

 @param filterMode 滤镜
 */
+(void) setFilterMode: (PiFilterMode)filterMode;

/**
 获得滤镜的名称

 @param filterMode 滤镜
 @return 滤镜的名称
 */
+ (NSString*)filterName:(PiFilterMode)filterMode;




/**
 得到 输入源 数据
 @return 输入源数据的数组，存有单个输入源的信息字典
 key:@"cn_name" 对应的value是中文名
 key:@"en_name" 对应的value是英文名
 key:@"" 对应的value是NSNumber格式的枚举值
 */
+ (NSArray *)getSourceModeDataDic;

/**
 得到 展开模式 数据
 @param sourceMode 输入源模式
 @return 展开模式数据的数组，存有单个展开模式的信息字典
 key:@"cn_name" 对应的value是中文名
 key:@"en_name" 对应的value是英文名
 key:@"" 对应的value是NSNumber格式的枚举值
 */
+ (NSArray *)getViewModeDataDicWithSoureceMode:(PiSourceMode)sourceMode;
/**
 得到 滤镜模式 数据
 @return 滤镜模式数据的数组，存有单个滤镜模式的信息字典
 key:@"cn_name" 对应的value是中文名
 key:@"en_name" 对应的value是英文名
 key:@"" 对应的value是NSNumber格式的枚举值
 */
+ (NSArray *)getfilterModeDataDic;
/**
 得到 动画模式 字典数据
 @return 动画模式数据的数组，存有单个动画模式的信息字典
 key:@"cn_name" 对应的value是中文名
 key:@"en_name" 对应的value是英文名
 key:@"" 对应的value是NSNumber格式的枚举值
 */
+ (NSArray *)getTransitionEffectDataDic;



@end

#endif /* PiPano_h */
