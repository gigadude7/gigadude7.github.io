//
//  BrotherListTableViewController.m
//  AttendaceSwiper
//
//  Created by Grant Hamilton Cordle on 1/17/16.
//  Copyright © 2016 Grant Hamilton Cordle. All rights reserved.
//

#import "BrotherListTableViewController.h"

@interface BrotherListTableViewController ()
//@property (weak) IBOutlet NSTextField *nameTextField;
//@property (weak) IBOutlet NSTextField *idTextField;

@end

@implementation BrotherListTableViewController


- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView {
    NSEntityDescription *entityDescription = [NSEntityDescription entityForName:@"Brother" inManagedObjectContext:[NSAppDelegate managedObjectContext]];
    
    NSFetchRequest *request = [[NSFetchRequest alloc] init];
    
    [request setEntity:entityDescription];
    
    NSError *error = nil;
    _brothers = [[NSAppDelegate managedObjectContext] executeFetchRequest:request error:&error];
    return _brothers.count;
}

#pragma mark - Table View Data Source
-(id)tableView:(NSTableView *)tableView objectValueForTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row {
    if ([tableColumn.identifier isEqualToString:@"Name"]) {
    //    _nameTextField.stringValue = [self.brothers[row] name];
        return [self.brothers[row] name];
    }
    else {
     //   _idTextField.stringValue = [self.brothers[row] idnumber];
        return [self.brothers[row] idnumber];
    }
}




@end
