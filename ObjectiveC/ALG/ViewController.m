//
//  ViewController.m
//  ALG
//
//  Created by junlongj on 2017/9/19.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    dispatch_queue_t queue = dispatch_queue_create("com.bestswifter.queue", nil);
    dispatch_sync(queue, ^{
        NSLog(@"current thread = %@", [NSThread currentThread]);
//        dispatch_sync(dispatch_get_main_queue(), ^{
//            NSLog(@"current thread = %@", [NSThread currentThread]);
//        });
    });

//    //ios 11
//    self.navigationController.navigationItem.searchController =  [[UISearchController alloc]initWithSearchResultsController:self];
//    self.automaticallyAdjustsScrollViewInsets = false;
//    self.view.safeAreaInsets;
//    UITableView *table;
//    table.adjustedContentInset;
//    self.additionalSafeAreaInsets;
//    self.navigationController.navigationBar.prefersLargeTitles = true;
//    // Do any additional setup after loading the view, typically from a nib.
//    [self.view layoutMargins];
//    [self viewRespectsSystemMinimumLayoutMargins];
//    [self viewSafeAreaInsetsDidChange];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
