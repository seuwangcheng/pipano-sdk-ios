# 集成PiPanoSDK到Xcode



## 一.使用限制

​	软件要求：iOS 8.0以上

​	硬件要求：iPhone5以后的 iPhone和iPad设备。==不支持iOS模拟器==





## 二.添加framework 到 Xcode工程

### 1.SDK压缩包目录结构

解压PiPanoSDKComplete.zip，会得到以下文件：

![压缩包](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-10-23-Snip20171020_1.png)

其中，`Data`，`Libraries`，`PiPanoSDKComplete.framework`，`PiPanoSDKCompleteBundle.bundle`是Xcode工程必须要的文件，`Demo`和`Doc`是示例工程和开发文档。

==如果要运行Demo示例工程，请把`PiPanoSDKComplete.framework`，`PiPanoSDKCompleteBundle.bundle`拷贝到Demo根目录。==





### 2.添加必要的文件到Xcode工程

#### 2.1 添加framework

首先把`PiPanoSDKComplete.framework`，`PiPanoSDKCompleteBundle.bundle` 添加到工程。

然后PiPanoSDK需要使用以下几个系统 framework ，也把它们添加到工程。

`MediaPlayer.framework`  `CoreMotion.framework` `CoreLocation.framework`

![Snip20170930_1](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-10-23-Snip20171020_3.png)





#### 2.2 添加Libraries

把PiPanoSDK的 `Libraries`目录添加到 Xcode工程根目录。如果已经存在相同名字目录，把`Libraries`里面2个.a文件合并进去即可。

![库文件](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-09-11-074440.jpg)

然后设置库搜索路径：Build Settings -> Library Search Paths：添加一个 `$(PROJECT_DIR)/Libraries`





#### 2.3 添加Data目录

把Data目录添加到 Xcode 工程根目录。==必须以引用的形式添加到工程。==

![data引用添加](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-09-11-074442.jpg)



![Data结果](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-09-11-074439.jpg)





#### 2.4 添加链接器flag

Build Settings -> Other Linker Flags：添加 `-force_load $(PROJECT_DIR)/PiPanoSDKComplete.framework/PiPanoSDKComplete`

![Snip20170930_2](http://fortylin-image.oss-cn-shenzhen.aliyuncs.com/doc/2017-10-23-Snip20171020_4.png)





## 三.修改入口代码

### 1.修改 main.m：

首先把`main.m`后缀名改为 mm。然后添加以下代码：

```objective-c
#import <UIKit/UIKit.h>
#import "AppDelegate.h"

//添加PiPanoSDK头文件
#import <PiPanoSDKComplete/PiPanoSDK.h>
#include <csignal>
const char* AppControllerClassName = "AppDelegate";

int main(int argc, char* argv[])
{
    @autoreleasepool
    {
        //PiPanoSDK需要的代码
        UnityInitRuntime(argc, argv);
      	RegisterFeatures();
        std::signal(SIGPIPE, SIG_IGN);
        
        UIApplicationMain(argc, argv, nil, [NSString stringWithUTF8String:AppControllerClassName]);
    }
    return 0;
}
```





### 2.修改AppDelegate

`AppDelegate.h`：

修改继承关系，把AppDelegate继承自`UnityAppController`。并且添加`willStartWithViewController`方法。

```objective-c
#import <UIKit/UIKit.h>
//添加PiPanoSDK头文件
#import <PiPanoSDKComplete/PiPanoSDK.h>

@interface AppDelegate : UnityAppController<UIApplicationDelegate>
- (void)willStartWithViewController:(UIViewController*)controller;
@end
```



`AppDelegate.m`：后缀名改为 mm。

1.实现`willStartWithViewController`方法，在这里设置你的项目主视图。

```objective-c
- (void)willStartWithViewController:(UIViewController*)controller {
    [super willStartWithViewController:controller];//调用父类方法
    
    //初始化你的主视图
    UIStoryboard *storyBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    MainViewController *mainVC = [storyBoard instantiateViewControllerWithIdentifier:@"idMainViewController"];
    
    //记录主视图的controller
    [super setMainViewController:mainVC mainViewNavigationCtler:nil];
}
```

2.UIApplication相关的几个方法内，必须先调用父类方法。

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  	//先调用父类方法
    [super application: application didFinishLaunchingWithOptions:launchOptions];
    
  	// Override point for customization after application launch.
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    //先调用父类方法
    [super applicationWillResignActive: application];
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    //先调用父类方法
    [super applicationDidEnterBackground: application];
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    //先调用父类方法
    [super applicationWillEnterForeground: application];
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    //先调用父类方法
    [super applicationDidBecomeActive: application];
   
}


- (void)applicationWillTerminate:(UIApplication *)application {
    //先调用父类方法
    [super applicationWillTerminate: application];
    
}
```



**经过以上更改，PiPano就成功整合在你的工程里了。**

