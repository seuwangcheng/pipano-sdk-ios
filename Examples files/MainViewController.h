//
//  MainViewController.h
//
//  Created by Forest Lin on 2017-4-18.
//
//

#import <UIKit/UIKit.h>

#import <CoreMotion/CoreMotion.h>

@interface MainViewController : UIViewController
{
    CMMotionManager *motionManager;
}

-(IBAction) loadPIView:(id)sender;
-(void) handleDeviceMotionUpdate:(CMDeviceMotion*)deviceMotion Error:(NSError*)error;

@end
