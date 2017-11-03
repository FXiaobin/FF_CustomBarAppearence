//
//  BaseNavigationController.m
//  FF_CustomBarAppearence
//
//  Created by fanxiaobin on 2017/9/27.
//  Copyright © 2017年 fanxiaobin. All rights reserved.
//

#import "BaseNavigationController.h"
#import "NextViewController.h"

@interface BaseNavigationController ()<UIGestureRecognizerDelegate>

@end

@implementation BaseNavigationController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

    SEL handleTransition = NSSelectorFromString(@"handleNavigationTransition:");
    UIPanGestureRecognizer *pan = [[UIPanGestureRecognizer alloc] initWithTarget:self.interactivePopGestureRecognizer.delegate action:handleTransition];
    pan.delegate = self;
    [self.view addGestureRecognizer:pan];
    self.interactivePopGestureRecognizer.enabled = NO;
    
    //2.利用KVC,修改系统返回手势的边界值
    //[self.interactivePopGestureRecognizer setValue:@([UIScreen mainScreen].bounds.size.width) forKeyPath:@"_recognizer._settings._edgeSettings._edgeRegionSize"];

}

#pragma mark - <UIGestureRecognizerDelegate>
/**
 * 每当用户触发[返回手势]时都会调用一次这个方法
 * 返回值:返回YES,手势有效; 返回NO,手势失效
 */
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer{
    // 如果当前显示的是第一个子控制器,就应该禁止掉[返回手势]
//    if (self.childViewControllers.count == 1){
//        return NO;
//    }else{
//        ///想让哪个控制器不侧滑 就判断一下
//        if ([self.topViewController isKindOfClass:[NextViewController class]]) {
//            return NO;
//        }
//        return YES;
//    }

    return self.childViewControllers.count > 1; // 处理后，就不会出现黑边效果的bug了。
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
