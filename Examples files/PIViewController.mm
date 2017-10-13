//
//  PIViewController.m
//
//  Created by Forest Lin on 2017-4-18.
//
//

#import "PIViewController.h"
#import <QuartzCore/QuartzCore.h>
#import <AVFoundation/AVFoundation.h>
#import "DeviceCameraUtil.h"

@interface PIViewController ()

@end



@implementation PIViewController

@synthesize startStopPreviewBtn;
@synthesize changeViewModeBtn;
@synthesize changeFilterModeBtn;
@synthesize changeTransitionBtn;

@synthesize playPhotoBtn;
@synthesize playOneEyeBtn;
@synthesize playTwoEyeBtn;
@synthesize playFull21Btn;

@synthesize playVideoBtn;
@synthesize stopPlayVideoBtn;
@synthesize pauseOrResumeVideoBtn;
@synthesize seekVideoVideoBtn;


NSString* mDocumentDirectory = nil;
NSDateFormatter* mDateFormat = nil;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    piCameraView = [PiPano getCameraView];
    
    //设置相机相关数据
    _dcUtil = [DeviceCameraUtil new];
    [_dcUtil setupCaptureSession:self];
    
    //把cameraView装入父view
    [superPICameraView setBounds:[[UIScreen mainScreen] bounds]];
    [superPICameraView addSubview:piCameraView];
    
    [playOneEyeBtn setHidden:YES];
    [playTwoEyeBtn setHidden:YES];
    [playFull21Btn setHidden:YES];
    
    [stopPlayVideoBtn setHidden:YES];
    [pauseOrResumeVideoBtn setHidden:YES];
    [seekVideoVideoBtn setHidden:YES];
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    mDocumentDirectory = [paths objectAtIndex:0];
    
}

// Delegate routine that is called when a sample buffer was written
- (void)captureOutput:(AVCaptureOutput *)captureOutput
didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
       fromConnection:(AVCaptureConnection *)connection
{
    CVPixelBufferRef imageBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    //把摄像头的数据给PiPano渲染
    [PiPano setVideoStreamFrame:imageBuffer];
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma MARK -- Methods
-(void)goBack:(id)sender
{
    [self.navigationController popViewControllerAnimated:YES];
}
-(void) setUnitySizeMax:(id)sender
{
    [piCameraView setBounds:[[UIScreen mainScreen] bounds]];
}
-(void) setUnitySizeMiddle:(id)sender
{
    [piCameraView setBounds:CGRectMake(0, 0, 350, 350)];
}
-(void) setUnitySizeSmall:(id)sender
{
    [piCameraView setBounds:CGRectMake(0, 0, 250, 250)];
    
}

bool mIsOpen = false;
-(IBAction) startStopSwitch:(id)sender
{
//    [PiPano setViewMode:PIVM_Immerse];
    if(!mIsOpen)
    {
        [PiPano startPreview: PISM_OneEye];//开始预览
        
        [startStopPreviewBtn setTitle:@"关闭预览" forState:UIControlStateNormal];
        NSString* modeName = [PiPano viewModeName:[PiPano getViewMode]];
        [changeViewModeBtn setTitle:modeName forState:UIControlStateNormal];
        
    }
    else
    {
        [PiPano stopPreview];
        [startStopPreviewBtn setTitle:@"开始预览" forState:UIControlStateNormal];
        
    }
    
    mIsOpen = !mIsOpen;
}

int mCurViewModeCount = 0;

-(void) changeViewMode:(id)sender
{
    mCurViewModeCount++;
    //按顺序逐个显示
    if(mCurViewModeCount >= PIVM_Max)
        mCurViewModeCount = PIVM_Immerse;
    
    [PiPano setViewMode:mCurViewModeCount];
    
    NSString* viewModeName = [PiPano viewModeName:mCurViewModeCount];
    [changeViewModeBtn setTitle:viewModeName forState:UIControlStateNormal];
}

int mCurFilterCount = -1;
- (void)changeFilterMode:(id)sender
{
    mCurFilterCount++;
    //按顺序逐个显示
    if(mCurFilterCount >= PIFM_Max )
        mCurFilterCount = PIFM_None;
    
    [PiPano setFilterMode:mCurFilterCount];
    
    NSString* filterName = [PiPano filterName:mCurFilterCount];
    [changeFilterModeBtn setTitle:filterName forState:UIControlStateNormal];
}

int mCurTransitionCount = -1;
- (void)changeTransitionMode:(id)sender
{
    mCurTransitionCount++;
    //按顺序逐个显示
    if(mCurTransitionCount >= PITE_Max)
        mCurTransitionCount = PITE_None;
    
    [PiPano setTransitionEffect:mCurTransitionCount];
    
    NSString* effectName = [PiPano transitionEffectName:mCurTransitionCount];
    [changeTransitionBtn setTitle:effectName forState:UIControlStateNormal];
}


- (void)playPhoto:(id)sender
{
    [playFull21Btn setHidden:NO];
    [playOneEyeBtn setHidden:NO];
    [playTwoEyeBtn setHidden:NO];
}

-(void)playOneEyePhoto:(id)sender
{
    NSString* photoPath = [[NSBundle mainBundle] pathForResource:@"testRes/one_eye_image" ofType:@"jpg"];
    [PiPano openPhoto:photoPath sourceMode: PISM_OneEye];
    
    [playOneEyeBtn setHidden:YES];
    [playFull21Btn setHidden:YES];
    [playTwoEyeBtn setHidden:YES];
}

-(void)playTwoEyePhoto:(id)sender
{
    NSString* photoPath = [[NSBundle mainBundle] pathForResource:@"testRes/two_eye_image" ofType:@"jpg"];
    [PiPano openPhoto:photoPath sourceMode: PISM_TwoEye];
    
    [playOneEyeBtn setHidden:YES];
    [playFull21Btn setHidden:YES];
    [playTwoEyeBtn setHidden:YES];
}

-(void)playFull21Photo:(id)sender
{
    NSString* photoPath = [[NSBundle mainBundle] pathForResource:@"testRes/full21_image" ofType:@"jpg"];
    [PiPano openPhoto:photoPath sourceMode: PISM_Full21];
    
    [playOneEyeBtn setHidden:YES];
    [playFull21Btn setHidden:YES];
    [playTwoEyeBtn setHidden:YES];
}

- (void)playVideo:(id)sender
{
    NSString* videoPath = [[NSBundle mainBundle] pathForResource:@"testRes/two_eye_video" ofType:@"mp4"];
    [PiPano openVideo:videoPath  sourceMode: PISM_TwoEye];
    
    
    [stopPlayVideoBtn setHidden:NO];
    [seekVideoVideoBtn setHidden:NO];
    [pauseOrResumeVideoBtn setHidden:NO];
}

- (void)stopPlayVideo:(id)sender
{
    [PiPano stopVideo];
    //mProgress = 1;
    
    [stopPlayVideoBtn setHidden:YES];
    [seekVideoVideoBtn setHidden:YES];
    [pauseOrResumeVideoBtn setHidden:YES];
}


float mProgress = 0;
- (void)seekVideo:(id)sender
{
    mProgress += 0.1f;
    if(mProgress > 1)
    mProgress = 0;

    [PiPano seekVideo:mProgress];
}

bool pauseOrResume = true;
- (void)pauseOrResumeVideo:(id)sender
{
    [PiPano getVideoProcess:^(float process){
        NSLog(@"process: %f",process);
    }];

    if(pauseOrResume)
    {
        [PiPano pauseVideo];
        [pauseOrResumeVideoBtn setTitle:@"继续" forState:UIControlStateNormal];
    }
    else
    {
        [PiPano resumeVideo];
        [pauseOrResumeVideoBtn setTitle:@"暂停" forState:UIControlStateNormal];
    }

    pauseOrResume = !pauseOrResume;
}


@end
