//
//  mainAppController.mm
//
//  Created by Forest Lin on 2017-4-18.
//
// The mainAppController.mm is my AppDelegate, you name it whatever you whant.
//

#import <UIKit/UIKit.h>
#import "UnityAppController.h"
#import "UI/UnityViewControllerBase.h"
#import "PiPano.h"
#import "CSVTableShare.h"

// This is your MAIN VIEWCONTROLLER, that controller you want to open first when build/open your app.
#import "MainViewController.h"

@interface mainAppController : UnityAppController<UIApplicationDelegate>

// My historyboard works with NavigationController.
// If your app doenst use navigation, just open the historiboard with your main ViewController.
@property (nonatomic, strong) UINavigationController *navigationController;

- (void)willStartWithViewController:(UIViewController*)controller;
@end



@implementation mainAppController

- (void)willStartWithViewController:(UIViewController*)controller {
    
    [super willStartWithViewController:controller];
   
    
    
    
    // Open your historyboard with your main view.
    // In my case i use navigation controller.
    
    [PiPano onPiPanoSDKReady:^()
     {
         NSLog(@"SDK is ok !");
//         [PiPano startPreview];//开始预览
//         NSString* photoPath = [[NSBundle mainBundle] pathForResource:@"testRes/two_eye" ofType:@"jpg"];
//         [PiPano openPhoto:photoPath];
         [PiPano setScreenOrientation: @"1"];
        
     }];
    
    UIStoryboard *storyBoard;
    storyBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];

    MainViewController *mainVC       = [storyBoard instantiateViewControllerWithIdentifier:@"idMainViewController"];
    self.navigationController = [[UINavigationController alloc] initWithRootViewController:mainVC];
    
//    [_rootView addSubview:self.navigationController.view];
    [super setMainViewController:mainVC mainViewNavigationCtler:self.navigationController];
    
}



@end


//
// You have to put this line below
//
IMPL_APP_CONTROLLER_SUBCLASS(mainAppController)
