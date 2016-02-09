//
//  BrotherEntry.h
//  AttendaceSwiper
//
//  Created by Grant Hamilton Cordle on 1/17/16.
//  Copyright © 2016 Grant Hamilton Cordle. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "AppDelegate.h"
#import "Brother+CoreDataProperties.h"

@interface BrotherEntry : NSViewController <NSTextFieldDelegate>
@property (strong) IBOutlet NSTextField *nameTextField;
@property (strong) IBOutlet NSTextField *numberTextField;
@property (strong) NSManagedObjectContext* moc; 
@property (strong) IBOutlet NSButton *addBrotherButton;
@property (strong) IBOutlet NSTextField *successLabel;


@end
