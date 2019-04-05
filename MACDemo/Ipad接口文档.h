//内存释放
//参数		
//result	二级指针
void WINAPI WXRelease(void* *p);

//接口对象释放
//参数		
//object	接口指针对象WxUser
void WINAPI WXObjectRelease(void* *object);

//同步消息回调函数定义
//参数		
//object	接口指针对象WxUser
//msg		消息内容,为json字符串
typedef int (WINAPI *SYNCMSGCALLBACK)(void* *object, const char *msg);

//设置同步消息回调函数
//参数		
//object	    接口指针对象WxUser
//sync_msg_cb	回调函数指针
int WINAPI WXSetSyncMsgCallBack(void** object, SYNCMSGCALLBACK sync_msg_cb);

//接收消息通知回调函数定义
//参数		
//object	接口指针对象WxUser
//type		通知类型
typedef int(__stdcall *RECVMSGCALLBACK)(void* *object, unsigned int type);

//设置接收消息通知回调函数
//参数		
//object	     接口指针对象WxUser
//sync_msg_cb	 回调函数指针
int WINAPI WXSetRecvMsgCallBack(void** object, RECVMSGCALLBACK sync_msg_cb);

//初始化接口
//参数		
//object	接口指针对象，分配一个WxUser
//device_name	设备名称
//device_type	网络信息等参数
//device_uuid	设备uuid
void* WINAPI WXInitialize(void* **object, const char *device_name, const char *device_type, const char *device_uuid);

//获取二维码
//参数
//object	接口指针对象WxUser
//result	二级指针，返回执行结果on字符串，返回执行结果
int WINAPI WXGetQRCode(void** object, char **result);

//检查二维码状态
//需循环调用。
//参数
//object	接口指针对象WxUser
//result	二级指针，返回执行结果串，返回执行结果
//0			未扫描
//1			已扫描
//2			已授权
//3			已过期
//4			已取消
int WINAPI WXCheckQRCode(void** object, char **result);

//二维码登陆
//参数
//object	接口指针对象WxUser
//user		用户名
//password	二维码验证密码
//result	二级指针，返回执行结果串，返回执行结果
int WINAPI WXQRCodeLogin(void** object, const char *user, const char *password, char **result);

//用户名登陆
//参数
//object	接口指针对象WxUser
//user		用户名
//password	密码明文
//result	二级指针，返回执行结果串，返回执行结果
int WINAPI WXUserLogin(void** object, const char *user, const char *password, char **result);

//手机登陆
//参数
//object	接口指针对象WxUser
//user		用户名
//password	手机验证密码
//result	二级指针，返回执行结果串，返回执行结果
int WINAPI WXPhoneLogin(void** object, const char *user, const char *password, char **result);

//注销
//参数
//object	接口指针对象WxUser
//user		用户名
//password	二维码密码
//result	二级指针，返回执行结果串，返回执行结果
int WINAPI WXLogout(void** object, char **result);

//发送文字消息
//参数
//object	接口指针对象WxUser
//user		对方用户名
//content	消息内容
//at		@好友列表，json数组
//result	二级指针，返回执行结果串，返回执行结果
int WINAPI WXSendMsg(void** object, const char *user, const char *content, const char *at, char **result);

//发送图片消息
//参数
//object	 接口指针对象WxUser
//user		 对方用户名
//image_data 图片数据
//image_size 图片大小
//result	 二级指针，返回执行结果串，返回执行结果
int WINAPI WXSendImage(void** object, const char *user, unsigned char *image_data, unsigned int image_size, char **result);

//发文字朋友圈
//参数
//object   接口指针对象WxUser
//content  文字消息内容
//result   二级指针，返回执行结果串，返回执行结果
int WINAPI WXSendMoments(void** object, const char *content, char **result);

//获取登陆验证码
//参数
//object	    接口指针对象WxUser
//phone_number	手机号码,格式+8613666666666
//result		二级指针，返回执行结果串，返回执行结果
int WINAPI WXGetLoginVerifyCode(void** object, const char *phone_number, char **result);

//发送登陆验证码
//参数
//object	    接口指针对象WxUser
//phone_number	手机号码,格式+8613666666666
//verify_code	验证码
//result		二级指针，返回执行结果串，返回执行结果
int WINAPI WXSendLoginVerifyCode(void** object, const char *phone_number, const char *verify_code, char **result);

//获取注册验证码
//参数
//object	    接口指针对象WxUser
//phone_number	手机号码,格式+8613666666666
//result		二级指针，返回执行结果串，返回执行结果
int WINAPI WXGetRegisterVerifyCode(void** object, const char *phone_number, char **result);

//发送注册验证码
//参数
//object	    接口指针对象WxUser
//phone_number	手机号码,格式+8613666666666
//verify_code	验证码
//result		二级指针，返回执行结果串，返回执行结果
int WINAPI WXSendRegisterVerifyCode(void** object, const char *phone_number, const char *verify_code, char **result);

//注册
//参数
//object	    接口指针对象WxUser
//phone_number	手机号码,格式+8613666666666
//nick_name		昵称
//result		二级指针，返回执行结果
int WINAPI WXRegister(void** object, const char *phone_number, const char *nick_name, char **result);

//消息同步，只同步聊天消息
//参数
//object	接口指针对象WxUser
int WINAPI WXSyncMessage(void** object) {

//消息同步，只同步通讯录消息
//参数
//object	接口指针对象WxUser
int WINAPI WXSyncContact(void** object) {

//获取用户信息
//参数
//object	接口指针对象WxUser
//user			对方用户名
//result		二级指针，返回执行结果
int WINAPI WXGetContact(void** object, const char *user, char **result);

//搜索用户信息
//参数
//object	接口指针对象WxUser
//user		对方用户名
//result	二级指针，返回执行结果
int WINAPI WXSearchContact(void** object, const char *user, char **result);

//添加好友请求
//参数
//object	    接口指针对象WxUser
//stranger_v1	对方stranger_v1字符串，例如v1_caa184cca67809743add39844a9a7a51cd4df982570340e8ae5f3cad28347ad4@stranger
//stranger_v2	对方stranger_v2字符串，例如v2_caa184cca67809743add39844a9a7a51cd4df982570340e8ae5f3cad28347ad4@stranger
//type			添加好友来源类型
//	type来源值：
//  2   -通过搜索邮箱
//	3   -通过微信号搜索
//	5   -通过朋友验证消息
//	7   -通过朋友验证消息(可回复)
//	12  -通过QQ好友添加
//	14  -通过群来源
//	15  -通过搜索手机号
//	16  -通过朋友验证消息
//	17  -通过名片分享
//	22  -通过摇一摇打招呼方式
//	25  -通过漂流瓶
//	30  -通过二维码方式
//verify	添加好友时的验证信息
//result	二级指针，返回执行结果
int WINAPI WXAddUser(void** object, const char *stranger_v1, const char *stranger_v2, int type, const char *verify, char **result);

//接受好友请求
//参数
//object	接口指针对象WxUser
//stranger	对方stranger字符串，例如v1_caa184cca67809743add39844a9a7a51cd4df982570340e8ae5f3cad28347ad4@stranger
//ticket	好友请求ticket
//result	二级指针，返回执行结果
int WINAPI WXAcceptUser(void** object, const char *stranger, const char *ticket, char **result);

//打招呼
//参数
//object	接口指针对象WxUser
//stranger	对方stranger串
//content	消息内容，可为空。为空时对方显示打了个招呼。
//result	二级指针，返回执行结果
int WINAPI WXSayHello(void** object, const char *stranger, const char *content, char **result);

//删除好友
//参数
//object	接口指针对象WxUser
//user		对方用户名
//result	二级指针，返回执行结果
int WINAPI WXDeleteUser(void** object, const char *user, char **result);

//创建群
//参数
//object	接口指针对象WxUser
//user		用户名json数组，例如["wxid_g58r112lnw0q22","my26259675"]
//result	二级指针，返回执行结果
int WINAPI WXCreateChatRoom(void** object, const char *user, char **result);

//添加群成员
//参数
//object	接口指针对象WxUser
//chatroom	群用户名
//user		成员用户名
//result	二级指针，返回执行结果
int WINAPI WXAddChatRoomMember(void** object, const char *chatroom, const char *user, char **result);

//邀请群成员
//参数
//object	接口指针对象WxUser
//chatroom	群用户名
//user		成员用户名
//result	二级指针，返回执行结果
int WINAPI WXInviteChatRoomMember(void** object, const char *chatroom, const char *user, char **result);

//删除群成员
//参数
//object	接口指针对象WxUser
//chatroom	群用户名
//user		成员用户名
//result	二级指针，返回执行结果
int WINAPI WXDeleteChatRoomMember(void** object, const char *chatroom, const char *user, char **result);

//退出群
//参数
//object	接口指针对象WxUser
//chatroom	群用户名
//result	二级指针，返回执行结果
int WINAPI WXQuitChatRoom(void** object, const char *chatroom, char **result);

//接收红包
//参数
//object	接口指针对象WxUser
//red_packet红包消息
//result	二级指针，返回执行结果
int WINAPI WXReceiveRedPacket(void** object, const char *red_packet, char **result);

//查看红包
//参数
//object	接口指针对象WxUser
//red_packet红包消息，与接收红包一样
//index		返回列表索引，一页11个。
//result	二级指针，返回执行结果
int WINAPI WXQueryRedPacket(void** object, const char *red_packet, unsigned int index, char **result);

//打开红包
//参数
//object	接口指针对象WxUser
//red_packet红包消息
//key		通过接受红包返回的key
//result	二级指针，返回执行结果
int WINAPI WXOpenRedPacket(void** object, const char *red_packet, const char *key, char **result);

//验证原密码
//参数
//object	接口指针对象WxUser
//password	原密码明文
//result	二级指针，返回执行结果
int WINAPI WXVerifyPassword(void** object, const char *password, char **result);

//设置新密码
//参数
//object	接口指针对象WxUser
//password	新密码明文
//result	二级指针，返回执行结果
int WINAPI WXSetPassword(void** object, const char *password, char **result)；

//设置头像
//参数
//object	接口指针对象WxUser
//image_data	图片数据
//image_size	图片大小
//result		二级指针，返回执行结果
	int WINAPI WXSetHeadImage(void** object, unsigned char *image_data, unsigned int image_size, char **result);

//2017-5-17 22:30:59 更新接口
//设置个人信息
//参数
//object	接口指针对象WxUser
//nick_name		昵称
//signature		签名
//sex			性别，1男，2女
//country		国家，CN
//provincia		地区，省，Zhejiang
//city			城市，Hangzhou
//result		二级指针，返回执行结果
int WINAPI WXSetUserInfo(void** object, const char *nick_name, const char *signature, unsigned int sex, const char *country, const char *provincia, const char *city, char **result);

//设置用户备注
//参数
//object	接口指针对象WxUser
//user			对方用户名
//signature		备注
//result		二级指针，返回执行结果
int WINAPI WXSetUserRemark(void** object, const char *user, const char *remark, char **result);

//查看附近的人
//参数
//object	接口指针对象WxUser
//longitude		浮点数，经度
//latitude		浮点数，维度
//result		二级指针，返回执行结果
int WINAPI WXGetPeopleNearby(void** object, float longitude, float latitude, char **result);

//获取群成员信息
//参数
//object	接口指针对象WxUser
//chatroom		群用户名
//result		二级指针，返回执行结果
int WINAPI WXGetChatRoomMember(void** object, const char *chatroom, char **result);

//心跳
//参数
//object	接口指针对象WxUser
//result		二级指针，返回执行结果
int WINAPI WXHeartBeat(void** object, char **result);

//获取公众号信息
//参数
//object	接口指针对象WxUser
//user			公众号用户名
//result		二级指针，返回执行结果
int WINAPI WXGetSubscriptionInfo(void** object, const char *user, char **result);

//执行公众号菜单操作
//参数
//object	接口指针对象WxUser
//user			公众号用户名
//id			菜单id，通过WXGetSubscriptionInfo获取
//key			菜单key，通过WXGetSubscriptionInfo获取
//result		二级指针，返回执行结果
int WINAPI WXSubscriptionCommand(void** object, const char *user, unsigned int id, const char *key, char **result);

//获取url访问token
//参数
//object	接口指针对象WxUser
//user			公众号用户名
//url			访问的链接
//result		二级指针，返回执行结果
int WINAPI WXGetRequestToken(void** object, const char *user, const char *url, char **result);

//访问url
//参数
//object	接口指针对象WxUser
//url			url地址
//key			token中的key
//uin			token中的uin
//result		二级指针，返回执行结果
int WINAPI WXRequestUrl(void** object, const char *url, const char *key, const char *uin, char **result);

//自动登录
//参数
//object	接口指针对象WxUser
//token			token登陆信息
//result		二级指针，返回执行结果
int WINAPI WXAutoLogin(void** object, const char *token, char **result);

//设置微信ID
//参数
//object	接口指针对象WxUser
//id			微信ID
//result		二级指针，返回执行结果
int WINAPI WXSetWeChatID(void** object, const char *id, char **result);

//获取登陆token
//参数
//object	接口指针对象WxUser
//result		二级指针，返回执行结果
int WINAPI WXGetLoginToken(void** object, char **result);

//加载62数据
//参数
//object	接口指针对象WxUser
//wx_data		62数据内容
//wx_size		62数据长度
//result		二级指针，返回执行结果
int WINAPI WXLoadWxDat(void** object, unsigned char *wx_data, unsigned int wx_size, char **result);

//生成62数据
//参数
//object	接口指针对象WxUser
//result		二级指针，返回执行结果
int WINAPI WXGenerateWxDat(void** object, char **result);

//查看转账信息
//参数
//object	接口指针对象WxUser
//transfer		转账消息
//result		二级指针，返回执行结果
int WINAPI WXTransferQuery(void** object, const char *transfer, char **result);

//接受转账
//参数
//object	接口指针对象WxUser
//transfer		转账消息
//result		二级指针，返回执行结果
int WINAPI WXTransferOperation(void** object, const char *transfer, char **result);

//设置http代理服务器
//参数
//object	接口指针对象WxUser
//proxy			http代理服务器，格式192.168.1.1:8888
//type			代理类型，1为http代理，2为socks4，3为socks5(需要用户名和密码)
//user			代理的用户名,socks5需要。
//password		代理的密码,socks5需要。
//result		二级指针，返回执行结果
int WINAPI WXSetProxyInfo(void** object, const char *proxy, int type, const char *user, const char *password, char **result);

//获取消息图片
//参数
//object	接口指针对象WxUser
//msg			收到的整个图片消息
//result		二级指针，返回执行结果
int WINAPI WXGetMsgImage(void** object, const char *msg, char **result);

//获取消息视频
//参数
//object	接口指针对象WxUser
//msg			收到的整个视频消息
//result		二级指针，返回执行结果
int WINAPI WXGetMsgVideo(void** object, const char *msg, char **result);

//获取消息语音(语音消息大于20秒时通过该接口获取)
//参数
//object	接口指针对象WxUser
//msg			收到的整个语音消息
//result		二级指针，返回执行结果
int WINAPI WXGetMsgVoice(void** object, const char *msg, char **result);

//搜索公众号
//参数
//object	接口指针对象WxUser
//user			公众号用户名
//result		二级指针，返回执行结果
int WINAPI WXWebSearch(void** object, const char *key, char **result);

//分享名片
//参数
//object	接口指针对象WxUser
//user			对方用户名
//id			名片的微信id
//caption		名片的标题
//result		二级指针，返回执行结果
int WINAPI WXShareCard(void** object, const char *user, const char *id, const char *caption, char **result);

//重置同步信息
//参数
//object	接口指针对象WxUser
int WINAPI WXSyncReset(void** object);

//获取其他设备登陆请求
//参数
//object	接口指针对象WxUser
//login_url		通过二维码扫描获取的url
//result		二级指针，返回执行结果
int WINAPI WXExtDeviceLoginGet(void** object, const char *login_url, char **result);

//确认其他设备登陆请求
//参数
//object	接口指针对象WxUser
//login_url		通过二维码扫描获取的url
//result		二级指针，返回执行结果
int WINAPI WXExtDeviceLoginOK(void** object, const char *login_url, char **result);

//取消其他设备登陆请求
//参数
//object	接口指针对象WxUser
//login_url		通过二维码扫描获取的url
//result		二级指针，返回执行结果
int WINAPI WXExtDeviceLoginCancel(void** object, const char *login_url, char **result);


//其他设备退出登陆
//参数
//object	接口指针对象WxUser
//result		二级指针，返回执行结果
int WINAPI WXExtDeviceLogout(void** object, char **result);

//扫描二维码获取信息
//参数
//object	接口指针对象WxUser
//path			本地二维码图片全路径
//result		二级指针，返回执行结果
int WINAPI WXQRCodeDecode(void** object, const char *path, char **result);

//朋友圈上传图片获取url
//参数
//object	接口指针对象WxUser
//image_data	图片数据
//image_size	图片大小
//result		二级指针，返回执行结果
int WINAPI WXSnsUpload(void** object, unsigned char *image_data, unsigned int image_size, char **result);

//获取朋友圈消息详情(例如评论)
//参数
//object	接口指针对象WxUser
//id			朋友圈消息id
//result		二级指针，返回执行结果
int WINAPI WXSnsObjectDetail(void** object, const char *id, char **result);

//朋友圈操作(删除朋友圈，删除评论，取消赞)
//参数
//object	接口指针对象WxUser
//id			朋友圈消息id
//type			操作类型,1为删除朋友圈，4为删除评论，5为取消赞
//comment		当type为4时，对应删除评论的id，通过WXSnsObjectDetail接口获取。当type为其他值时，comment不可用，置为0。
//comment_type	评论类型,当删除评论时可用，2或者3.(规律未知)
//result		二级指针，返回执行结果
int WINAPI WXSnsObjectOp(void** object, const char *id, int type, int comment, int comment_type, char **result);

//朋友圈消息评论
//参数
//object	接口指针对象WxUser
//user			对方用户名
//id			朋友圈消息id
//content		评论内容
//reply_id		回复的id    //如果想回复某人的评论，就加上他的comment_id  否则就用0
//result		二级指针，返回执行结果
int WINAPI WXSnsComment(void** object, const char *user, const char *id, const char *content, unsigned int reply_id, char **result);

//获取好友朋友圈信息
//参数
//object	接口指针对象WxUser
//user			对方用户名
//id			获取到的最后一次的id，第一次调用设置为空
//result		二级指针，返回执行结果
int WINAPI WXSnsUserPage(void** object, const char *user, const char *id, char **result);

//获取朋友圈动态
//参数
//object	接口指针对象WxUser
//id			获取到的最后一次的id，第一次调用设置为空
//result		二级指针，返回执行结果
int WINAPI WXSnsTimeline(void** object, const char *id, char **result);

//发送APP消息(分享应用或者朋友圈链接等)
//参数
//object	接口指针对象WxUser
//user			对方用户名
//content		消息内容(整个消息结构<appmsg xxxxxxxxx>)
//result		二级指针，返回执行结果
int WINAPI WXSendAppMsg(void** object, const char *user, const char *content, char **result);

//同步收藏消息(用户获取收藏对象的id)
//参数
//object	接口指针对象WxUser
//key			同步的key，第一次调用设置为空。
//result		二级指针，返回执行结果
int WINAPI WXFavSync(void** object, const char *key, char **result);

//添加收藏
//参数
//object	接口指针对象WxUser
//fav_object	收藏对象结构(<favitem type=5xxxxxx)
//result		二级指针，返回执行结果
int WINAPI WXFavAddItem(void** object, const char *fav_object, char **result);

//获取收藏对象的详细信息
//参数
//object	接口指针对象WxUser
//id			收藏对象id
//result		二级指针，返回执行结果
int WINAPI WXFavGetItem(void** object, unsigned int id, char **result);

//删除收藏对象
//参数
//object	接口指针对象WxUser
//id			收藏对象id
//result		二级指针，返回执行结果
int WINAPI WXFavDeleteItem(void** object, unsigned int id, char **result);

//获取所有标签列表
//参数
//object	接口指针对象WxUser
//result		二级指针，返回执行结果
int WINAPI WXGetContactLabelList(void** object, char **result);

//添加标签到列表
//参数
//object	接口指针对象WxUser
//label			标签内容
//result		二级指针，返回执行结果
int WINAPI WXAddContactLabel(void** object, const char *label, char **result);

//从列表删除标签
//参数
//object	接口指针对象WxUser
//id			标签id
//result		二级指针，返回执行结果
int WINAPI WXDeleteContactLabel(void** object, const char *id, char **result);

//设置用户标签
//参数
//object	接口指针对象WxUser
//user			用户名
//id			标签id
//result		二级指针，返回执行结果
int WINAPI WXSetContactLabel(void** object, const char *user, const char *id, char **result);

//获取用户二维码(自己或者已加入的群)
//参数
//object	接口指针对象WxUser
//user			用户名
//style			是否使用风格化二维码
//result		二级指针，返回执行结果
int WINAPI WXGetUserQRCode(void** object, const char *user, unsigned int style, char **result);

//AppMsg上传数据
//参数
//object	接口指针对象WxUser
//media_data	数据内容
//media_size	数据大小
//result		二级指针，返回执行结果
int WINAPI WXUploadAppAttach(void** object, unsigned char *media_data, unsigned int media_size, char **result);

//发送语音消息(微信silk格式语音)
//参数
//object	接口指针对象WxUser
//user			对方用户名
//voice_data	语音数据
//voice_size	语音大小
//voice_time	语音时间(毫秒，最大60 * 1000)
//result		二级指针，返回执行结果
int WINAPI WXSendVoice(void** object, const char *user, unsigned char *voice_data, unsigned int voice_size, unsigned int voice_time, char **result);

//发送登陆请求
//参数
//object	接口指针对象WxUser
//token			登陆token数据
//result		二级指针，返回执行结果
int WINAPI WXLoginRequest(void** object, const char *token, char **result);

//同步朋友圈动态(好友评论或点赞自己朋友圈的消息)
//参数
//object	接口指针对象WxUser
//key			同步key
//result		二级指针，返回执行结果
int WINAPI WXSnsSync(void** object, const char *key, char **result);

//群发消息
//参数
//object	接口指针对象WxUser
//user			用户名json数组 ["AB1","AC2","AD3"]
//content		消息内容
//result		二级指针，返回执行结果
int WINAPI WXMassMessage(void** object, const char *user, const char *content, char **result);

//设置群昵称
//参数
//object	接口指针对象WxUser
//chatroom	群用户名
//name	昵称  
//result		二级指针，返回执行结果
int WINAPI WXSetChatroomName(void** object, const char *chatroom, const char *name, char **result);

//设置群公告
//参数
//object	接口指针对象WxUser
//chatroom	群用户名
//announcement	公告内容
//result		二级指针，返回执行结果
int WINAPI WXSetChatroomAnnouncement(void** object, const char *chatroom, const char *announcement, char **result);

//登陆验证问题处理
//参数
//object	接口指针对象WxUser
//ticket		登录失败需要验证时返回的url里面的ticket，例如https://xxxxxxxxxl_lang=zh_CN&ticket=2_d2132d65c303912bf9f232b4f31739c9，取2_d2132d65c303912bf9f232b4f31739c9。
//cookies		当前接口返回的cookies，第一次请求设置为空，会返回一个cookies
//answer		答案，字符串，第一次请求设置为空。例如选择第一个答案，则为"1"，如果为多选题，答案格式为"1|2"，用"|"隔开。
//result		二级指针，返回执行结果
int WINAPI WXLoginQuestion(void** object, const char *ticket, const char *cookies, const char *answer, char **result);

//解析登陆接口返回值信息
//参数
//object	接口指针对象WxUser
//code			返回值code，字符串类型，例如"-20".
//result		二级指针，返回执行结果
int WINAPI WXLoginQuestionResult(void** object, const char *code, char **result);

//申请一个申诉请求
//参数
//object	接口指针对象WxUser
//result		二级指针，返回执行结果
int WINAPI WXAppealSession(void** object, char **result);

//获取申诉请求验证码图片
//返回的验证码图片以base64加密的形式存放在response中。
//参数
//object	接口指针对象WxUser
//cookies		WXAppealSession接口返回的cookies
//result		二级指针，返回执行结果
int WINAPI WXAppealVerifyCode(void** object, const char *cookies, char **result);

//申诉请求
//参数
//object	接口指针对象WxUser
//cookies		WXAppealVerifyCode接口返回的cookies
//user_name		需要申诉的用户名
//phone_number	可接受短信的手机号
//verify_code	WXAppealVerifyCode接口返回的验证码
//result		二级指针，返回执行结果
int WINAPI WXAppealRequest(void** object, const char *cookies, const char *user_name, const char *phone_number, const char *verify_code, char **result);

//获取好友辅助验证码
//手机发送验证信息以后调用该接口。
//参数
//object	接口指针对象WxUser
//cookies		WXAppealVerifyCode接口返回的cookies
//msg			WXAppealRequest接口返回的response的值，例如{"smstype":"up","acctcc":"86","acctmobile":"1367****505","smsvcode":"zm","smsnum":"123","ret":0,"msg":"","appealid":"123","showtel":0}
//result		二级指针，返回执行结果
int WINAPI WXAppealSms(void** object, const char *cookies, const char *msg, char **result);

//获取已参与申诉的好友列表
//参数
//object	接口指针对象WxUser
//cookies		WXAppealVerifyCode接口返回的cookies
//msg			WXAppealSms接口返回的response的值，例如{"wxacct":"xxxx","verifynumber":"12345","ret":4,"msg":"","appealid":"123","showtel":0}
//result		二级指针，返回执行结果
int WINAPI WXAppealVerifyFriend(void** object, const char *cookies, const char *msg, char **result);

//解析申诉接口返回值信息
//参数
//object	接口指针对象WxUser
//code			返回值code，字符串类型，例如"-20".
//result		二级指针，返回执行结果
int WINAPI WXAppealResult(void** object, const char *code, char **result);
