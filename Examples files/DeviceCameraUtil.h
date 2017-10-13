//
//  DeviceCameraUtil.h
//  TestPiPanoSDK
//
//  Created by forest lin on 2017/7/26.
//  Copyright © 2017年 vxinyou. All rights reserved.
//

#ifndef DeviceCameraUtil_h
#define DeviceCameraUtil_h

#import <AVFoundation/AVFoundation.h>
@interface DeviceCameraUtil :  AVCaptureVideoPreviewLayer

- (void)setupCaptureSession: (id)delegate;

@end
#endif /* DeviceCameraUtil_h */
