//
//  Define.h
//  FF_CustomBarAppearence
//
//  Created by fanxiaobin on 2017/11/3.
//  Copyright © 2017年 fanxiaobin. All rights reserved.
//

#ifndef Define_h
#define Define_h

///打印日志
#ifdef DEBUG
#define DDLog(...) NSLog(@"%s-[第%d行]-NSLog: %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define DDLog(...)

#endif

///弱引用
#define kWeakSelf(type)  __weak typeof(type) weak##type = type;
///强引用
#define kStrongSelf(type)  __strong typeof(type) type = weak##type;

//分辨率比例
#define UI_S_CALE  [UIScreen mainScreen].bounds.size.width / 750.f
#define k_SCALE(value)  value * UI_S_CALE
///字体
#define kFont(fontSize) [UIFont systemFontOfSize:fontSize]

#pragma mark ---- 高度部分

///屏幕宽度
#define kScreenWidth   [UIScreen mainScreen].bounds.size.width
///屏幕高度
#define kScreenHeight  [UIScreen mainScreen].bounds.size.height
///TabBar高度
#define kTabBarHeight  49.0
/// iPhoneX顶部宏
#define kNavigationBarHeight         (kScreenHeight == 812.0 ? 88.0 : 64.0)
/// iPhoneX底部宏
#define kSafeAreaBottomHeight        (kScreenHeight == 812.0 ? 34.0 : 0.0)
///是否是iPhone X
#define kIsIPhoneX                   (kScreenHeight == 812.0 ? YES : NO)

#pragma mark ---- 单例部分

#define kApplication        [UIApplication sharedApplication]
#define kKeyWindow          [UIApplication sharedApplication].keyWindow
#define kAppDelegate        [UIApplication sharedApplication].delegate
///通知中心单例
#define kNotificationCenter                 [NSNotificationCenter defaultCenter]
///本地存储单例
#define kUserDefaults                       [NSUserDefaults standardUserDefaults]
#define kUserDefaultsGetObj(key)            [kUserDefaults objectForKey:key]
#define kUserDefaultsSetObj(obj,key)        [kUserDefaults setObject:obj forKey:key]

#pragma mark --- 颜色部分
///随机颜色
#define kRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]
///色值颜色
#define kHexColor(rgbValue)  [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 blue:((float)(rgbValue & 0xFF)) / 255.0 alpha:1.0]

#define kHexAlphaColor(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:a]

///RGB颜色
#define KRGBColor(r, g, b)      [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define kRGBAColor(r, g, b, a)  [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:alpha]
///透明色
#define kClearColor [UIColor clearColor]
#define TITLE_COLOR         HexRGB(0x333333)
#define CONTENT_COLOR       HexRGB(0x666666)
#define TIME_COLOR          HexRGB(0x999999)
#define PLACEHOLDER_COLOR   HexRGB(0xcccccc)
#define SEPARATE_COLOR      HexRGB(0xe5e5e5)

///角度转换弧度
#define kDegreesToRadian(x)         (M_PI * (x) / 180.0)
///弧度转换角度
#define kRadianToDegrees(radian)    (radian*180.0)/(M_PI)

///获取图片资源
#define kPlaceholderImage       [UIImage imageNamed:@""]
#define kGetImage(imageName)    [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]

///判断是否为iPhone
//#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IPHONE ([[[UIDevice currentDevice] model] isEqualToString:@"iPhone"])

///判断是否为iPad
//#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPAD ([[[UIDevice currentDevice] model] isEqualToString:@"iPad"])

///判断是否为ipod
#define IS_IPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

///判断是否为 iPhone 5SE
#define iPhone5SE [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f

///判断是否为iPhone 6/6s
#define iPhone6_6s [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f

///判断是否为iPhone 6Plus/6sPlus
#define iPhone6Plus_6sPlus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f

///获取系统版本
#define IOS_SYSTEM_STRING [[UIDevice currentDevice] systemVersion]
////APP版本号
#define kAppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
///UUIDString
#define kDeviceID   [[[UIDevice currentDevice] identifierForVendor] UUIDString]

///判断 iOS 8 或更高的系统版本
#define IOS_VERSION_8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) ? (YES):(NO))

/// 判断是不是iOS系统，如果是iOS系统在真机和模拟器输出都是YES
#if TARGET_OS_IPHONE
//真机
#endif

#if (TARGET_IPHONE_SIMULATOR)
// 在模拟器的情况下
#else
// 在真机情况下
#endif

#pragma mark ---- 路径部分
///获取temp
#define kPathTemp NSTemporaryDirectory();
///获取沙盒 Document
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
///获取沙盒 Cache
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject];

///字符串是否为空
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
///数组是否为空
#define kArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
///字典是否为空
#define kDictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)





///常量
NSString * const kLoginSuccessNotification = @"kLoginSuccessNotification";





#endif /* Define_h */
