/*
 * Author: Landon Fuller <landonf@plausible.coop>
 *
 * Copyright (c) 2013 Plausible Labs Cooperative, Inc.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#import <Foundation/Foundation.h>
#import "PLClangCursor.h"
#import "PLClangDiagnostic.h"
#import "PLClangToken.h"

@interface PLClangTranslationUnit : NSObject

/** The original source file name of this translation unit. */
@property(nonatomic, readonly) NSString *spelling;

/** An ordered array of PLClangDiagnostic instances generated by parsing this translation unit. */
@property(nonatomic, readonly) NSArray *diagnostics;

/** If YES, the code could not be properly parsed and is ill-formed. Review the array of diagnostics for more details. */
@property(nonatomic, readonly) BOOL didFail;

/** The cursor representing this translation unit. */
@property(nonatomic, readonly) PLClangCursor *cursor;

- (PLClangCursor *) cursorForSourceLocation: (PLClangSourceLocation *) sourceLocation;
- (NSArray *) tokensForSourceRange: (PLClangSourceRange *) range;
- (BOOL) writeToFile: (NSString *) path error: (NSError **) error;

@end