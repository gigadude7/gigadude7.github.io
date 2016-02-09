//
//  Swiping.m
//  AttendaceSwiper
//
//  Created by Grant Hamilton Cordle on 1/17/16.
//  Copyright © 2016 Grant Hamilton Cordle. All rights reserved.
//

#import "Swiping.h"
#import "AppDelegate.h"

@interface Swiping ()

@end

@implementation Swiping

- (void)viewDidLoad {
    [super viewDidLoad];
    [self loadBrothers];
    [self createEvent];
}


- (void)createEvent {
    //get current date
    _startDate = [NSDate date];
    _lateDate = [NSDate dateWithTimeInterval:600 sinceDate:_startDate];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc]init];
    [dateFormatter setDateFormat:@"dd_MM_YY_HH_mm_ss"];
    NSString *dateString = [dateFormatter stringFromDate:_startDate];
    NSLog(@"%@",dateString);
    
    _filePath = [NSString stringWithFormat:@"/Users/Grant/Desktop/%@", dateString];
    
    //create text file with date name
    [[NSFileManager defaultManager] createFileAtPath:_filePath contents:nil attributes:nil];
    
    
    
}

-(void) loadBrothers {
    NSEntityDescription *entityDescription = [NSEntityDescription entityForName:@"Brother" inManagedObjectContext:[NSAppDelegate managedObjectContext]];
    
    NSFetchRequest *request = [[NSFetchRequest alloc] init];
    
    [request setEntity:entityDescription];
    
    NSError *error = nil;
    _activeBrothers = [[NSAppDelegate managedObjectContext] executeFetchRequest:request error:&error];
}


- (IBAction)signInButtonPressed:(id)sender {
    NSLog(@"%d", _textFieldManual.intValue);
    NSDate* signInDate = [NSDate date]; 
    for (Brother* bro in _activeBrothers) {
        if ((bro.idnumber.intValue == _textFieldManual.intValue) && ([_lateDate compare:signInDate] == NSOrderedDescending)) {
            NSLog(@"logged in");
            NSString* brotherLoginInfo = [NSString stringWithFormat:@"%@: On Time", bro.name];
            [brotherLoginInfo writeToFile:_filePath atomically:YES encoding:NSUTF8StringEncoding error:nil];
        }
        else if (bro.idnumber.intValue == _textFieldManual.intValue) {
            NSLog(@"logged in");
            NSString* brotherLoginInfo = [NSString stringWithFormat:@"%@: Late", bro.name];
            [brotherLoginInfo writeToFile:_filePath atomically:YES encoding:NSUTF8StringEncoding error:nil];
        }
        
        
    }
}

@end
