//
//  BrotherListTableViewController.h
//  AttendaceSwiper
//
//  Created by Grant Hamilton Cordle on 1/17/16.
//  Copyright © 2016 Grant Hamilton Cordle. All rights reserved.
//

#import "Brother+CoreDataProperties.h"
#import "AppDelegate.h"
#import <Cocoa/Cocoa.h>

@interface BrotherListTableViewController : NSViewController<NSTableViewDataSource, NSTableViewDelegate>
@property (strong) IBOutlet NSTextFieldCell *lastName;
@property (strong) IBOutlet NSTextFieldCell *firstName;
@property (strong) IBOutlet NSTextFieldCell *studentID;
@property (strong) NSArray* brothers;

@end
