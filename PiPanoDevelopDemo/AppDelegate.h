//
//  AppDelegate.h
//  TestPiPanoSDK
//
//  Created by forest on 2017/6/2.
//  Copyright © 2017年 pisoftware. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PiPanoSDKComplete/PiPanoSDK.h>

@interface AppDelegate : UnityAppController<UIApplicationDelegate>

// My historyboard works with NavigationController.
// If your app doenst use navigation, just open the historiboard with your main ViewController.
@property (nonatomic, strong) UINavigationController *navigationController;


- (void)willStartWithViewController:(UIViewController*)controller;


@end

