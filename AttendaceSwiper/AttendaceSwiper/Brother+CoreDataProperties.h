//
//  Brother+CoreDataProperties.h
//  AttendaceSwiper
//
//  Created by Grant Hamilton Cordle on 1/17/16.
//  Copyright © 2016 Grant Hamilton Cordle. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "Brother.h"

NS_ASSUME_NONNULL_BEGIN

@interface Brother (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *name;
@property (nullable, nonatomic, retain) NSNumber *idnumber;
@property (nullable, nonatomic, retain) NSString *idn; 

@end

NS_ASSUME_NONNULL_END
