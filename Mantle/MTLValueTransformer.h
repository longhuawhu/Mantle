//
//  MTLValueTransformer.h
//  Mantle
//
//  Created by Justin Spahr-Summers on 2012-09-11.
//  Copyright (c) 2012 GitHub. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MTLTransformerErrorHandling.h"

// A block that represents a transformation.
//
// value   - The value to transform.
// success - The block must set this parameter to indicate whether the
//           transformation was successful.
//           MTLValueTransformer will always call this block with *success set
//           to YES.
// error   - If not NULL, this may be set to an error that occurs during
//           transforming the value.
//
// Returns the result of the transformation, which may be nil.
typedef id (^MTLValueTransformationBlock)(id value, BOOL *success, NSError **error);

//
// A value transformer supporting block-based transformation.
//
@interface MTLValueTransformer : NSValueTransformer <MTLTransformerErrorHandling>

// Returns a transformer which transforms values using the given block. Reverse
// transformations will not be allowed.
+ (instancetype)transformerUsingBlock:(MTLValueTransformationBlock)transformation;

// Returns a transformer which transforms values using the given block, for
// forward or reverse transformations.
+ (instancetype)reversibleUsingBlock:(MTLValueTransformationBlock)transformation;

// Returns a transformer which transforms values using the given blocks.
+ (instancetype)reversibleTransformerUsingForwardBlock:(MTLValueTransformationBlock)forwardTransformation reverseBlock:(MTLValueTransformationBlock)reverseTransformation;

@end

typedef id (^MTLValueTransformerBlock)(id);

@interface MTLValueTransformer (Deprecated)

+ (instancetype)transformerWithBlock:(MTLValueTransformerBlock)transformationBlock __attribute__((deprecated));

+ (instancetype)reversibleTransformerWithBlock:(MTLValueTransformerBlock)transformationBlock __attribute__((deprecated));

+ (instancetype)reversibleTransformerWithForwardBlock:(MTLValueTransformerBlock)forwardBlock reverseBlock:(MTLValueTransformerBlock)reverseBlock __attribute__((deprecated));

@end
