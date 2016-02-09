//
//  AppDelegate.h
//  AttendaceSwiper
//
//  Created by Grant Hamilton Cordle on 1/12/16.
//  Copyright © 2016 Grant Hamilton Cordle. All rights reserved.
//

#define NSAppDelegate   (AppDelegate *)[[NSApplication sharedApplication]delegate]

#import <Cocoa/Cocoa.h>
#import "Brother.h"

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;


@property (strong) NSArray<Brother*> *brothers;


@end

