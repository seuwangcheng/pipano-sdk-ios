//
//  PIViewController.h
//
//  Created by Forest Lin on 2017-4-18.
//
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <PiPanoSDKComplete/PiPanoSDK.h>
#import "DeviceCameraUtil.h"

@interface PIViewController : UIViewController<AVCaptureAudioDataOutputSampleBufferDelegate>
{
    IBOutlet UIView     *superPICameraView;
    UIView* piCameraView;
    
}
@property (nonatomic, retain) DeviceCameraUtil *dcUtil;

@property (nonatomic,retain) IBOutlet UIButton* startStopPreviewBtn;
@property (nonatomic,retain) IBOutlet UIButton* changeViewModeBtn;

@property (nonatomic,retain) IBOutlet UIButton* changeFilterModeBtn;
@property (nonatomic,retain) IBOutlet UIButton* changeTransitionBtn;

@property (nonatomic,retain) IBOutlet UIButton* playPhotoBtn;
@property (nonatomic,retain) IBOutlet UIButton* playTwoEyeBtn;
@property (nonatomic,retain) IBOutlet UIButton* playOneEyeBtn;
@property (nonatomic,retain) IBOutlet UIButton* playFull21Btn;

@property (nonatomic,retain) IBOutlet UIButton* playVideoBtn;

@property (nonatomic,retain) IBOutlet UIButton* stopPlayVideoBtn;
@property (nonatomic,retain) IBOutlet UIButton* pauseOrResumeVideoBtn;
@property (nonatomic,retain) IBOutlet UIButton* seekVideoVideoBtn;

-(IBAction) goBack:(id)sender;
//Unity窗口大小
-(IBAction) setUnitySizeMax:(id)sender;
-(IBAction) setUnitySizeMiddle:(id)sender;
-(IBAction) setUnitySizeSmall:(id)sender;

//控制预览
-(IBAction) startStopSwitch:(id)sender;
-(IBAction) changeViewMode:(id)sender;
-(IBAction) changePanoMode:(id)sender;

-(IBAction) changeFilterMode:(id)sender;
-(IBAction) changeTransitionMode:(id)sender;

//播放图片或视频
-(IBAction) playPhoto:(id)sender;
-(IBAction) playOneEyePhoto:(id)sender;
-(IBAction) playTwoEyePhoto:(id)sender;
-(IBAction) playFull21Photo:(id)sender;

-(IBAction) playVideo:(id)sender;
-(IBAction) stopPlayVideo:(id)sender;

-(IBAction) pauseOrResumeVideo:(id)sender;
-(IBAction) seekVideo:(id)sender;

@end
