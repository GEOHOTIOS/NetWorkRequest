//
//  SVHTTPClient.h
//  网络请求
//
//  Created by Macbook Pro on 16/2/29.
//  Copyright © 2016年 Macbook Pro. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^SVHTTPRequestCompletionHandler)(id response, NSHTTPURLResponse *urlResponse, NSError *error);

@class SVHTTPRequest;
@interface SVHTTPClient : NSObject
+ (SVHTTPClient*)sharedClient;
+ (SVHTTPClient*)sharedClientWithIdentifier:(NSString*)identifier;

- (void)setBasicAuthWithUsername:(NSString*)username password:(NSString*)password;
- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;

/*GET请求获取数据*/
- (SVHTTPRequest*)GET:(NSString*)path parameters:(NSDictionary*)parameters completion:(SVHTTPRequestCompletionHandler)completionBlock;
/*GET请求获取数据并保存到某个路径下*/
- (SVHTTPRequest*)GET:(NSString*)path parameters:(NSDictionary*)parameters saveToPath:(NSString*)savePath progress:(void (^)(float progress))progressBlock completion:(SVHTTPRequestCompletionHandler)completionBlock;
/*POST网络请求获取数据*/
- (SVHTTPRequest*)POST:(NSString*)path parameters:(NSObject*)parameters completion:(SVHTTPRequestCompletionHandler)completionBlock;
/*POST网络请求 获取数据 返回值 服务器时间 错误信息*/
- (SVHTTPRequest*)POST:(NSString*)path parameters:(NSObject*)parameters progress:(void (^)(float progress))progressBlock completion:(void (^)(id response, NSHTTPURLResponse *urlResponse, NSError *error))completionBlock;
/*把消息的本体发送到一个URL 向服务器发送请求，如果URI不存在，则要求服务器根据请求创建资源，如果存在，服务器就接受请求内容，并修改URI资源的原始版本。*/
- (SVHTTPRequest*)PUT:(NSString*)path parameters:(NSObject*)parameters completion:(SVHTTPRequestCompletionHandler)completionBlock;
/*通过HTTP请求删除服务器上的制定资源*/
- (SVHTTPRequest*)DELETE:(NSString*)path parameters:(NSDictionary*)parameters completion:(SVHTTPRequestCompletionHandler)completionBlock;
/*HEAD方法跟GET方法相同，只不过服务器响应时不会返回消息体。一个HEAD请求的响应中，HTTP头中包含的元信息应该和一个GET请求的响应消息相同。这种方法可以用来获取请求中隐含的元信息，而不用传输实体本身。也经常用来测试超链接的有效性、可用性和最近的修改。*/
- (SVHTTPRequest*)HEAD:(NSString*)path parameters:(NSDictionary*)parameters completion:(SVHTTPRequestCompletionHandler)completionBlock;

- (void)cancelRequestsWithPath:(NSString*)path;
- (void)cancelAllRequests;


@property (nonatomic, strong) NSDictionary *baseParameters;

@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *basePath;
@property (nonatomic, strong) NSString *userAgent;

@property (nonatomic, readwrite) BOOL sendParametersAsJSON;
@property (nonatomic, readwrite) NSURLRequestCachePolicy cachePolicy;
@property (nonatomic, readwrite) NSUInteger timeoutInterval;



@end
