//
//  UIScrollView+IOS11.m
//  FF_CustomBarAppearence
//
//  Created by fanxiaobin on 2017/11/3.
//  Copyright © 2017年 fanxiaobin. All rights reserved.
//

#import "UIScrollView+IOS11.h"

@implementation UIScrollView (IOS11)

- (void)configIOS11{
    
    if (@available(iOS 11.0, *)) {
        self.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        //iPhoneX这里是88
        //self.contentInset = UIEdgeInsetsMake(64, 0, 49, 0);
        //self.scrollIndicatorInsets = _tableView.contentInset;
        
        if ([self isKindOfClass:[UITableView class]]) {
            UITableView *tableView = (UITableView *)self;
            tableView.estimatedRowHeight = 0;
            tableView.estimatedSectionHeaderHeight = 0;
            tableView.estimatedSectionFooterHeight = 0;
        }
    }
}

- (void)configIOS11WithController:(UIViewController *)viewController{
    
    if (@available(iOS 11.0, *)) {
        self.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
    
        if ([self isKindOfClass:[UITableView class]]) {
            UITableView *tableView = (UITableView *)self;
            tableView.estimatedRowHeight = 0;
            tableView.estimatedSectionHeaderHeight = 0;
            tableView.estimatedSectionFooterHeight = 0;
        }
        
    }else{
        viewController.automaticallyAdjustsScrollViewInsets = NO;
    }
}

@end
