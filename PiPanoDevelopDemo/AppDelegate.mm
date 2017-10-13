//
//  AppDelegate.m
//  TestPiPanoSDK
//
//  Created by forest on 2017/6/2.
//  Copyright © 2017年 pisoftware. All rights reserved.
//

#import "AppDelegate.h"
#import "MainViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (void)willStartWithViewController:(UIViewController*)controller {
    
    [super willStartWithViewController:controller];//调用父类方法
    
    //初始化你的主视图
    UIStoryboard *storyBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    MainViewController *mainVC       = [storyBoard instantiateViewControllerWithIdentifier:@"idMainViewController"];
    self.navigationController = [[UINavigationController alloc] initWithRootViewController:mainVC];
    
    //记录主视图的controller
    [super setMainViewController:mainVC mainViewNavigationCtler:self.navigationController];
    
    [PiPano onPiPanoSDKReady:^()
     {
         NSLog(@"SDK is ok !");
         [PiPano setScreenOrientation: @"1"];
         
     }];
}


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //先调用父类方法
    [super application: application didFinishLaunchingWithOptions:launchOptions];
    // Override point for customization after application launch.
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    //先调用父类方法
    [super applicationWillResignActive: application];
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    //先调用父类方法
    [super applicationDidEnterBackground: application];
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    //先调用父类方法
    [super applicationWillEnterForeground: application];
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    //先调用父类方法
    [super applicationDidBecomeActive: application];
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    //先调用父类方法
    [super applicationWillTerminate: application];
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
