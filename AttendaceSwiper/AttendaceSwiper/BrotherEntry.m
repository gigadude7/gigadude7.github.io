//
//  BrotherEntry.m
//  AttendaceSwiper
//
//  Created by Grant Hamilton Cordle on 1/17/16.
//  Copyright © 2016 Grant Hamilton Cordle. All rights reserved.
//

#import "BrotherEntry.h"

@interface BrotherEntry ()

@end

@implementation BrotherEntry

bool shouldClear = NO;

- (void)viewDidLoad {
    [super viewDidLoad];
    _moc = [NSAppDelegate managedObjectContext];
    _nameTextField.delegate = self;
    _numberTextField.delegate = self;
    
    
    // Do view setup here.
}

-(void)controlTextDidChange:(NSNotification *)obj {
    if (shouldClear) {
        _successLabel.stringValue = @"";
    }
}


- (IBAction)brotherButtonHit:(id)sender {
    shouldClear = NO;
    Brother* newBrother = [NSEntityDescription insertNewObjectForEntityForName:@"Brother" inManagedObjectContext:_moc];
    newBrother.name = _nameTextField.stringValue;
    NSNumber* nwi = [NSNumber numberWithInteger:_numberTextField.integerValue];
    newBrother.idnumber = nwi;
    newBrother.idn = _numberTextField.stringValue;
    
    NSError *error = nil;
    if ([_moc save:&error] == NO) {
        NSAssert(NO, @"Error saving context: %@\n%@", [error localizedDescription], [error userInfo]);
    }
    else {
        _nameTextField.stringValue = @"";
        _numberTextField.stringValue = @"";
        
        shouldClear = YES;
        
        NSLog(@"Brother successfuly added");
        [_successLabel setStringValue:@"Success!"];
        
    }
}

@end
