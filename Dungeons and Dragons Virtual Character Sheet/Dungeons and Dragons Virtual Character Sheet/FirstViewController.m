//
//  FirstViewController.m
//  Dungeons and Dragons Virtual Character Sheet
//
//  Created by Grant Hamilton Cordle on 7/21/15.
//  Copyright (c) 2015 Grant Hamilton Cordle. All rights reserved.
//

#import "FirstViewController.h"

@interface FirstViewController ()
@property (weak, nonatomic) IBOutlet UITableView *characterAttributeTable;

@end

@implementation FirstViewController

NSMutableDictionary *characterAttributes;
                                    

- (void)viewDidLoad {
    [super viewDidLoad];
    characterAttributes = [[NSMutableDictionary alloc] initWithObjectsAndKeys:
                           @"Strength", [NSNumber numberWithInt:(10)],
                           @"Dexterity", [NSNumber numberWithInt:(10)],
                           @"Constitution", [NSNumber numberWithInt:(10)],
                           @"Intelligence", [NSNumber numberWithInt:(10)],
                           @"Wisdom", [NSNumber numberWithInt:(10)],
                           @"Charisma", [NSNumber numberWithInt:(10)], nil];
    
}

- (void) populateCharacterAttributeTable {
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
