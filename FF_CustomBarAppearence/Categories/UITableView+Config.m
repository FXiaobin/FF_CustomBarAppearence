//
//  UITableView+Config.m
//  gdfg
//
//  Created by fanxiaobin on 2017/9/27.
//  Copyright © 2017年 fanxiaobin. All rights reserved.
//

#import "UITableView+Config.h"

@implementation UITableView (Config)

- (void)configIOS11{
    
    if (@available(iOS 11.0, *)) {
        self.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        //iPhoneX这里是88
        //self.contentInset = UIEdgeInsetsMake(64, 0, 49, 0);
        //self.scrollIndicatorInsets = _tableView.contentInset;
        self.estimatedRowHeight = 0;
        self.estimatedSectionHeaderHeight = 0;
        self.estimatedSectionFooterHeight = 0;
    }
}

- (void)configIOS11WithController:(UIViewController *)viewController{
    
    if (@available(iOS 11.0, *)) {
        self.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        //iPhoneX这里是88
        //self.contentInset = UIEdgeInsetsMake(64, 0, 49, 0);
        //self.scrollIndicatorInsets = _tableView.contentInset;
        self.estimatedRowHeight = 0;
        self.estimatedSectionHeaderHeight = 0;
        self.estimatedSectionFooterHeight = 0;
        
    }else{
        viewController.automaticallyAdjustsScrollViewInsets = NO;
    }
}


@end
