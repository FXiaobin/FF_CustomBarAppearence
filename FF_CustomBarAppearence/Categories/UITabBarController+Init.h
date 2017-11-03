//
//  UITabBarController+Init.h
//  FF_CustomBarAppearence
//
//  Created by fanxiaobin on 2017/9/27.
//  Copyright © 2017年 fanxiaobin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITabBarController (Init)

///自定义导航条显示
- (void)customNavigationBarAppearence;

///创建UITabBarController
- (void)setupTabBarControllerWithViewControllerNames:(NSArray *)viewControllerNames titles:(NSArray *)titles normalImages:(NSArray *)normalImages selectedImages:(NSArray *)selectedImages;

@end
