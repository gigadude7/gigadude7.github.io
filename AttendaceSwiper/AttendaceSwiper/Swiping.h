//
//  Swiping.h
//  AttendaceSwiper
//
//  Created by Grant Hamilton Cordle on 1/17/16.
//  Copyright © 2016 Grant Hamilton Cordle. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface Swiping : NSViewController <NSTextFieldDelegate, NSTextDelegate>

@property (strong) IBOutlet NSTextField *textFieldAutomatic;
@property (strong) IBOutlet NSTextField *textFieldManual;
@property (strong) IBOutlet NSButton *loginButton;

@property (strong) NSDate* startDate;
@property (strong) NSDate* lateDate;

@property (strong) NSArray* activeBrothers;
@property (strong) NSString* filePath;


@end
