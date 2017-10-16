//
//  PiPanoSDK.h
//  Unity-iPhone
//
//  Created by forest on 2017/5/18.
//
//

#ifndef PiPano_Specific_h
#define PiPano_Specific_h

#import "PiPano.h"

@interface PiPano (Specific)

+(PiViewMode) defaultViewMode;

+(PiSourceMode) defaultSourceMode;

+(PiCameraDirection) defaultCameraDir;

/**
 获取PiPanoSDK版本号

 @return 一串数字的版本号
 */
+(NSString*) getVersion;


/**
 获取PiPanoSDK build版本号

 @return 带有version key的版本号
 */
+(NSString*) getBuildVersionString;


@end

#endif /* PiPano_Specific_h */
