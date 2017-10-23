# Integrate PiPanoSDK into Xcode

## Ⅰ.Restrictions

​	Software: iOS 8.0 or later

​	Device：iPhone5 or later  iPhone or iPad devices.   **iOS simulator is not supported.**





## Ⅱ.Integrate PiPanoSDK into Xcode Project

### 1.PiPanoSDK File Directory Info

Unzip PiPanoSDKComplete.zip, get PiPanoSDK directory.

![zip](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-10-23-Snip20171020_1.png)

Xcode required directories and files: `Data`, `Libraries`, `PiPanoSDKComplete.framework`，`PiPanoSDKCompleteBundle.bundle`

There is a develop docment and API preferences in `Doc`,  and there is a simple demo project in `Demo`. 

**If you want run the demo project, you need to copy`PiPanoSDKComplete.framework` and `PiPanoSDKCompleteBundle.bundle` to  `Demo`.**





### 2.Add Framework and Libraries to Your project

#### 2.1 Add Framework

Add `PiPanoSDKComplete.framework`, `PiPanoSDKCompleteBundle.bundle` to your Xcode project.

Then add three system frameworks which PiPanoSDK depends: 

`MediaPlayer.framework`  `CoreMotion.framework` `CoreLocation.framework`

![Snip20170930_1](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-10-23-Snip20171020_3.png)





#### 2.2 Add Libraries

Add  `Libraries` to the root directory of your project. If your project already had the Libraries directory named   `Libraries` , just add  the mappano.a and libAVProVideoiOS.a to your  `Libraries`.

![Libraries](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-09-11-074440.jpg)

Set Library Search Paths:  Build Settings -> Library Search Paths：add  `$(PROJECT_DIR)/Libraries`.





#### 2.3 Add Data Folder

Add `Data` to your project , make sure **add folder with Create folder references**.

![add-data](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-09-11-074442.jpg)



![add-data-result](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-09-11-074439.jpg)





#### 2.4 Add Linker Flag

Build Settings -> Other Linker Flags：add  `-force_load $(PROJECT_DIR)/PiPanoSDKComplete.framework/PiPanoSDKComplete`

![Snip20170930_2](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-10-23-Snip20171020_4.png)





## Ⅲ. Motify main.m and AppDelegate

### 1.Motify main.m：

Change `main.m` to  main.mm,  and add some code:

```objective-c
#import <UIKit/UIKit.h>
#import "AppDelegate.h"

//PiPanoSDK Header
#import <PiPanoSDKComplete/PiPanoSDK.h>
#include <csignal>
const char* AppControllerClassName = "AppDelegate";

int main(int argc, char* argv[])
{
    @autoreleasepool
    {
        //PiPanoSDK code
        UnityInitRuntime(argc, argv);
      	RegisterFeatures();
        std::signal(SIGPIPE, SIG_IGN);
        
        UIApplicationMain(argc, argv, nil, [NSString stringWithUTF8String:AppControllerClassName]);
    }
    return 0;
}
```



**Because of using C function in PiPanoSDK, if you import PiPanoSDK.h in m file, your have to change the suffix to mm.**



### 2.Modify AppDelegate

In `AppDelegate.h` : 

Change inheritance relationship, AppDelegate inherited from `UnityAppController` .  Add method`willStartWithViewController`.

```objective-c
#import <UIKit/UIKit.h>
//添加PiPanoSDK头文件
#import <PiPanoSDKComplete/PiPanoSDK.h>

@interface AppDelegate : UnityAppController<UIApplicationDelegate>
- (void)willStartWithViewController:(UIViewController*)controller;
@end
```



In `AppDelegate.m` :  change suffix to mm.

1.Implement method `willStartWithViewController`, and define your main UIView in it.

```objective-c
- (void)willStartWithViewController:(UIViewController*)controller {
    [super willStartWithViewController:controller];//call super method first
    
    //init your main UIView
    UIStoryboard *storyBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    MainViewController *mainVC = [storyBoard instantiateViewControllerWithIdentifier:@"idMainViewController"];
    
    //set your main view controller
    [super setMainViewController:mainVC mainViewNavigationCtler:nil];
}
```

2.Call super method first in these methods:

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  	//call super method first
    [super application: application didFinishLaunchingWithOptions:launchOptions];
    
  	// Override point for customization after application launch.
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    //call super method first
    [super applicationWillResignActive: application];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    //call super method first
    [super applicationDidEnterBackground: application];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    //call super method first
    [super applicationWillEnterForeground: application];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    //call super method first
    [super applicationDidBecomeActive: application];
   
}

- (void)applicationWillTerminate:(UIApplication *)application {
    //call super method first
    [super applicationWillTerminate: application];
    
}
```



**After these changes, PiPanoSDK is successfully integrated into your project.**

