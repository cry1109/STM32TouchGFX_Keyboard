#ifndef _PINYIN_H
#define _PINYIN_H

#include <gui/containers/Keyboard.hpp>

typedef struct
{
	char* Number;		//输入的数字字符串
	char* Input;		//对应的拼音
	wchar_t* Chinese;	//码表
}PinyinDef;

const wchar_t PY_mb_a[] = { L"啊阿腌吖锕厑嗄錒呵腌" };
const wchar_t PY_mb_ai[] = { L"爱埃挨哎唉哀皑癌蔼矮艾碍隘捱嗳嗌嫒瑷暧砹锿霭" };
const wchar_t PY_mb_an[] = { L"安俺按暗岸案鞍氨谙胺埯揞犴庵桉铵鹌黯" };
const wchar_t PY_mb_ang[] = { L"昂盎肮骯" };
const wchar_t PY_mb_ao[] = { L"凹敖熬翱袄傲奥懊澳坳拗嗷螯鏊鳌鏖岙廒遨媪骜獒聱" };
const wchar_t PY_mb_ba[] = { L"八巴爸拔芭捌扒叭吧笆疤跋靶把耙坝霸罢茇菝岜灞钯粑鲅魃" };
const wchar_t PY_mb_bai[] = { L"白柏百摆佰败拜稗伯捭掰" };
const wchar_t PY_mb_ban[] = { L"半办斑班搬扳般颁板版扮拌伴瓣绊阪坂贲钣瘢癍舨" };
const wchar_t PY_mb_bang[] = { L"邦帮梆榜膀绑棒磅蚌镑傍谤蒡浜" };
const wchar_t PY_mb_bao[] = { L"包宝保抱报暴苞胞褒剥薄雹堡饱豹鲍爆刨炮勹葆孢煲鸨褓趵龅" };
const wchar_t PY_mb_bei[] = { L"背贝北倍杯碑悲卑辈钡狈备惫焙被臂孛陂邶埤萆蓓呗悖碚鹎褙鐾鞴" };;
const wchar_t PY_mb_ben[] = { L"本笨奔苯畚坌贲锛" };
const wchar_t PY_mb_beng[] = { L"蚌崩绷甭泵蹦迸堋嘣甏" };
const wchar_t PY_mb_bi[] = { L"逼鼻比鄙笔彼碧蓖蔽毕毙毖币庇痹闭匕敝弊必辟壁臂避陛秘泌俾埤芘荜荸萆薜吡哔狴庳愎滗濞弼妣婢嬖璧贲畀铋秕裨筚箅篦舭襞跸髀" };
const wchar_t PY_mb_bian[] = { L"边编贬便变卞鞭扁辨辩辫遍匾弁苄忭汴缏煸砭碥窆褊蝙笾鳊" };
const wchar_t PY_mb_biao[] = { L"表标彪膘婊骠杓飑飙飚镖镳瘭裱鳔髟" };
const wchar_t PY_mb_bie[] = { L"别鳖憋瘪蹩" };
const wchar_t PY_mb_bin[] = { L"彬斌濒滨宾摈傧豳缤玢槟殡膑镔髌鬓" };
const wchar_t PY_mb_bing[] = { L"兵冰柄丙秉饼炳病并屏禀冫邴摒槟" };
const wchar_t PY_mb_bo[] = { L"柏百剥薄博玻菠卜播拨钵波勃搏铂箔伯帛舶脖膊渤泊驳孛亳蕃啵饽檗擘礴钹鹁簸趵跛踣" };
const wchar_t PY_mb_bu[] = { L"不布步堡捕卜哺补埠簿部怖埔卟逋瓿晡钚钸醭" };
const wchar_t PY_mb_ca[] = { L"擦嚓礤" };
const wchar_t PY_mb_cai[] = { L"才财睬猜裁材踩采彩菜蔡" };
const wchar_t PY_mb_can[] = { L"餐参蚕残惭惨灿孱骖璨粲黪" };
const wchar_t PY_mb_cang[] = { L"苍舱仓沧藏伧" };
const wchar_t PY_mb_cao[] = { L"草操糙槽曹艹嘈漕螬艚" };
const wchar_t PY_mb_ce[] = { L"侧册测厕策恻" };
const wchar_t PY_mb_cen[] = { L"参岑涔" };
const wchar_t PY_mb_ceng[] = { L"层蹭曾噌" };
const wchar_t PY_mb_cha[] = { L"插叉茬茶查碴搽察岔差诧刹喳衩嚓猹馇汊姹杈楂槎檫锸镲" };
const wchar_t PY_mb_chai[] = { L"差拆柴豺侪钗瘥虿龇" };
const wchar_t PY_mb_chan[] = { L"产阐颤搀掺蝉馋谗缠铲孱单冁谄蒇廛忏潺澶羼婵觇禅镡蟾躔" };
const wchar_t PY_mb_chang[] = { L"长厂昌猖场尝常偿肠敞畅唱倡伥鬯苌菖徜怅惝阊娼嫦昶氅鲳" };
const wchar_t PY_mb_chao[] = { L"超抄钞朝嘲潮巢吵炒绰剿怊晁耖" };
const wchar_t PY_mb_che[] = { L"车扯撤掣彻澈坼屮砗" };
const wchar_t PY_mb_chen[] = { L"郴臣辰尘晨忱沉陈趁衬称谌谶抻嗔宸琛榇碜龀" };
const wchar_t PY_mb_cheng[] = { L"撑称城橙成呈乘程惩澄诚承逞骋秤盛丞埕噌徵枨柽塍瞠铖铛裎蛏酲" };
const wchar_t PY_mb_chi[] = { L"吃痴持匙池迟弛驰耻齿侈尺赤翅斥炽笞叱哧傺坻墀茌啻嗤彳饬媸敕眵鸱瘛褫蚩螭篪豉踟魑" };
const wchar_t PY_mb_chong[] = { L"充冲虫崇宠种重茺忡憧铳舂艟雠" };
const wchar_t PY_mb_chou[] = { L"抽酬丑畴踌稠愁筹仇绸瞅臭俦帱惆瘳雠" };
const wchar_t PY_mb_chu[] = { L"出初橱厨躇锄雏滁除楚础储矗搐触处畜亍刍怵憷绌杵楮樗褚蜍蹰黜" };
const wchar_t PY_mb_chuai[] = { L"揣搋嘬膪踹" };
const wchar_t PY_mb_chuan[] = { L"川穿椽传船喘串舛遄巛氚钏舡" };
const wchar_t PY_mb_chuang[] = { L"疮窗幢床闯创怆疒" };
const wchar_t PY_mb_chui[] = { L"吹炊捶锤垂陲棰槌" };
const wchar_t PY_mb_chun[] = { L"春椿醇唇淳纯蠢莼鹑蝽" };
const wchar_t PY_mb_chuo[] = { L"戳绰啜辶辍踔龊" };
const wchar_t PY_mb_ci[] = { L"此刺赐次伺差疵茨磁雌辞慈瓷词兹茈呲祠鹚粢糍" };
const wchar_t PY_mb_cong[] = { L"从丛聪葱囱匆苁淙骢琮璁枞" };
const wchar_t PY_mb_cou[] = { L"凑楱辏腠" };
const wchar_t PY_mb_cu[] = { L"粗醋簇促蔟徂猝殂酢蹙蹴" };
const wchar_t PY_mb_cuan[] = { L"蹿篡窜攒汆撺爨镩" };
const wchar_t PY_mb_cui[] = { L"摧崔催脆瘁粹淬翠萃啐悴璀榱毳隹" };
const wchar_t PY_mb_cun[] = { L"村存寸忖皴" };
const wchar_t PY_mb_cuo[] = { L"磋撮搓措挫错厝嵯脞锉矬痤瘥鹾蹉躜" };
const wchar_t PY_mb_da[] = { L"大搭达答瘩打耷哒嗒怛妲沓疸褡笪靼鞑" };
const wchar_t PY_mb_dai[] = { L"大呆歹傣戴带殆代贷袋待逮怠黛埭甙呔岱迨骀绐玳" };
const wchar_t PY_mb_dan[] = { L"耽担丹单郸掸胆旦氮但惮淡诞弹蛋赡石儋萏啖澹殚赕眈疸瘅聃箪" };
const wchar_t PY_mb_dang[] = { L"当挡党荡档谠凼菪宕砀铛裆" };
const wchar_t PY_mb_dao[] = { L"刀捣蹈倒岛祷导到稻悼道盗刂叨帱忉氘焘纛" };
const wchar_t PY_mb_de[] = { L"德得的地锝" };
const wchar_t PY_mb_dei[] = { L"得" };
const wchar_t PY_mb_deng[] = { L"澄蹬灯登等瞪凳邓噔嶝戥磴镫簦" };
const wchar_t PY_mb_di[] = { L"的抵底地蒂第帝弟递堤低滴迪敌笛狄涤翟嫡缔提氐籴诋谛邸坻荻嘀娣柢棣觌砥碲睇镝羝骶" };
const wchar_t PY_mb_dia[] = { L"嗲" };
const wchar_t PY_mb_dian[] = { L"电店惦点典靛奠淀殿颠掂滇碘垫佃甸阽坫巅玷钿癜癫簟踮" };
const wchar_t PY_mb_diao[] = { L"吊刁掉钓调碉叼雕凋铞铫貂鲷" };
const wchar_t PY_mb_die[] = { L"跌爹碟蝶迭谍叠垤堞揲喋牒瓞耋蹀鲽" };
const wchar_t PY_mb_ding[] = { L"丁盯叮钉顶鼎锭定订仃啶玎腚碇町铤疔耵酊" };
const wchar_t PY_mb_diu[] = { L"丢铥" };
const wchar_t PY_mb_dong[] = { L"东冬董懂动栋侗恫冻洞咚岽峒氡胨胴硐鸫" };
const wchar_t PY_mb_dou[] = { L"豆逗痘都兜抖斗陡蔸窦蚪篼" };
const wchar_t PY_mb_du[] = { L"肚度渡都督毒犊独读堵睹赌杜镀妒芏嘟渎椟牍蠹笃髑黩" };
const wchar_t PY_mb_duan[] = { L"端短锻段断缎椴煅簖" };
const wchar_t PY_mb_dui[] = { L"堆兑队对怼憝碓" };
const wchar_t PY_mb_dun[] = { L"盾墩吨蹲敦顿囤钝遁沌炖砘礅盹镦趸" };
const wchar_t PY_mb_duo[] = { L"多朵度掇哆夺垛躲跺舵剁惰堕驮咄哚沲缍铎裰踱" };
const wchar_t PY_mb_e[] = { L"阿蛾峨鹅俄额讹娥恶厄扼遏鄂饿哦噩谔垩苊莪萼呃愕屙婀轭腭锇锷鹗颚鳄" };
const wchar_t PY_mb_ei[] = { L"诶" };
const wchar_t PY_mb_en[] = { L"恩蒽摁" };
const wchar_t PY_mb_er[] = { L"二而儿耳尔饵洱贰迩珥铒鸸鲕" };
const wchar_t PY_mb_fa[] = { L"发罚筏伐乏阀法珐垡砝" };
const wchar_t PY_mb_fan[] = { L"凡烦反返范贩犯饭泛藩帆番翻樊矾钒繁蕃蘩幡梵燔畈蹯" };
const wchar_t PY_mb_fang[] = { L"坊芳方肪房防妨仿访纺放匚邡枋钫舫鲂" };
const wchar_t PY_mb_fei[] = { L"菲非啡飞肥匪诽吠肺废沸费芾狒斐悱妃绯淝榧贲腓扉砩镄痱蜚篚翡霏鲱" };
const wchar_t PY_mb_fen[] = { L"分芬奋份忿愤粪酚吩氛纷坟焚汾粉偾瀵玢棼贲鲼鼢" };
const wchar_t PY_mb_feng[] = { L"丰封枫蜂峰锋风凤疯烽逢冯缝讽奉俸酆葑唪沣砜" };
const wchar_t PY_mb_fo[] = { L"佛" };
const wchar_t PY_mb_fou[] = { L"否缶" };
const wchar_t PY_mb_fu[] = { L"复佛傅付阜父夫敷肤孵妇扶拂辐幅氟符伏俘服浮涪福袱弗甫抚辅俯釜斧脯腑府腐赴副覆赋腹负富讣附缚咐匐凫阝郛芙芾苻茯莩菔拊呋幞怫滏艴孚驸绂绋桴赙祓砩黻黼罘稃馥蚨蜉蝠蝮麸趺跗鲋鳆" };
const wchar_t PY_mb_ga[] = { L"噶嘎夹咖伽尬尕尜旮钆" };
const wchar_t PY_mb_gai[] = { L"该改概钙盖溉芥丐陔垓戤赅胲" };
const wchar_t PY_mb_gan[] = { L"干甘杆柑竿肝赶感秆敢赣坩苷尴擀泔淦澉绀橄旰矸疳酐" };
const wchar_t PY_mb_gang[] = { L"冈刚钢缸肛纲岗港杠扛戆罡筻" };
const wchar_t PY_mb_gao[] = { L"告皋高膏篙羔糕搞镐稿睾诰郜藁缟槔槁杲锆" };
const wchar_t PY_mb_ge[] = { L"个各盖哥骼膈歌搁戈鸽胳疙割革葛格蛤阁隔铬合咯鬲仡哿圪塥嗝纥搿铪镉袼虼舸" };
const wchar_t PY_mb_gei[] = { L"给" };
const wchar_t PY_mb_gen[] = { L"根跟亘茛哏艮" };
const wchar_t PY_mb_geng[] = { L"耕更庚羹埂耿梗颈哽赓绠鲠" };
const wchar_t PY_mb_gong[] = { L"工共攻功恭公宫弓龚供躬巩汞拱贡蚣廾珙肱觥" };
const wchar_t PY_mb_gou[] = { L"钩勾沟苟够垢构购佝诟狗篝岣遘媾缑枸觏彀笱鞲" };
const wchar_t PY_mb_gu[] = { L"姑估沽孤菇咕辜箍鼓古蛊骨谷股故顾固雇贾嘏诂菰崮汩梏轱牯牿臌毂瞽罟钴锢鸪鹄痼蛄酤觚鲴鹘" };
const wchar_t PY_mb_gua[] = { L"刮瓜剐寡挂褂卦诖呱栝胍鸹" };
const wchar_t PY_mb_guai[] = { L"乖拐怪掴" };
const wchar_t PY_mb_guan[] = { L"关官冠观管馆罐惯灌贯纶倌莞棺掼涫盥鹳鳏" };
const wchar_t PY_mb_guang[] = { L"光广逛咣犷桄胱" };
const wchar_t PY_mb_gui[] = { L"瑰规圭硅归龟闺轨鬼诡桂柜跪贵刽癸炔匦刿庋宄妫桧炅晷皈簋鲑鳜" };
const wchar_t PY_mb_gun[] = { L"辊滚棍衮绲磙鲧" };
const wchar_t PY_mb_guo[] = { L"锅郭国果裹过涡馘埚掴呙帼崞猓椁虢锞聒蜾蝈" };
const wchar_t PY_mb_ha[] = { L"哈蛤铪" };
const wchar_t PY_mb_hai[] = { L"还咳孩海害氦亥骇骸嗨胲醢" };
const wchar_t PY_mb_han[] = { L"汗汉喊寒含涵函罕酣旱憾悍焊憨邯韩翰撼鼾捍邗菡撖瀚晗焓顸颔蚶" };
const wchar_t PY_mb_hang[] = { L"行夯杭航吭巷沆绗颃" };
const wchar_t PY_mb_hao[] = { L"郝好耗号昊皓毫浩灏镐壕嚎豪貉蒿薅嗥嚆濠颢蚝" };
const wchar_t PY_mb_he[] = { L"呵喝荷菏核禾和何合河盒貉阂涸赫贺褐鹤吓诃劾壑嗬阖纥曷盍颌蚵翮" };
const wchar_t PY_mb_hei[] = { L"黑嘿" };
const wchar_t PY_mb_hen[] = { L"痕很狠恨" };
const wchar_t PY_mb_heng[] = { L"哼亨横衡恒蘅珩桁" };
const wchar_t PY_mb_hong[] = { L"红轰哄烘虹鸿洪宏弘黉訇讧荭蕻薨闳泓" };
const wchar_t PY_mb_hou[] = { L"后喉侯猴吼厚候堠後逅瘊篌糇鲎骺" };
const wchar_t PY_mb_hu[] = { L"护互沪户核呼乎忽瑚壶葫胡蝴虎狐糊湖弧唬冱唿囫岵猢怙惚浒滹琥槲轷觳烀煳戽扈祜瓠鹄鹕鹱虍笏醐斛鹘" };
const wchar_t PY_mb_hua[] = { L"花华猾滑哗画划化话骅桦砉铧" };
const wchar_t PY_mb_huai[] = { L"坏槐徊怀淮踝" };
const wchar_t PY_mb_huan[] = { L"欢环桓还缓换患唤痪焕涣宦幻鬟浣豢郇奂垸萑擐圜獾洹漶寰逭缳锾鲩" };
const wchar_t PY_mb_huang[] = { L"晃荒慌黄磺蝗簧皇凰惶煌幌恍谎隍徨湟潢遑璜肓癀蟥篁鳇" };
const wchar_t PY_mb_hui[] = { L"会回毁悔灰挥辉徽恢蛔慧卉惠晦贿秽烩汇讳诲绘彗溃诙茴荟蕙咴哕喙隳洄浍缋桧晖恚虺蟪麾" };
const wchar_t PY_mb_hun[] = { L"荤昏婚魂浑混诨馄阍溷珲" };
const wchar_t PY_mb_huo[] = { L"和豁活伙火获或惑霍货祸劐藿攉嚯夥钬锪镬耠蠖" };
const wchar_t PY_mb_ji[] = { L"计记给技击基几脊己圾籍集及急疾汲即嫉级挤蓟既忌际冀季伎祭剂机畸稽积肌饥迹激讥鸡姬绩缉吉极棘箕辑悸济寄寂妓继纪藉奇系丌亟乩剞佶偈墼芨芰荠萁蒺蕺掎叽咭哜唧岌嵴洎彐屐骥畿玑楫殛戟戢赍觊犄齑矶羁嵇稷瘠虮笈笄暨跻跽霁鲚鲫髻麂" };
const wchar_t PY_mb_jia[] = { L"家加嘉夹佳荚颊贾甲钾假稼价架驾嫁枷茄嘏伽郏葭岬浃迦珈戛胛恝铗铪镓痂瘕袷蛱笳袈跏" };
const wchar_t PY_mb_jian[] = { L"建见件简健减歼荐监捡俭剪坚尖间煎兼肩艰奸缄茧检柬碱硷拣笺槛鉴践贱键箭舰剑饯渐溅涧僭谏谫谮菅蒹搛囝湔蹇謇缣枧楗戋戬牮犍毽腱睑锏鹣裥笕翦趼踺鲣鞯" };
const wchar_t PY_mb_jiang[] = { L"讲虹僵姜将浆江疆蒋桨奖匠酱降强茳洚绛缰犟礓耩糨豇" };
const wchar_t PY_mb_jiao[] = { L"叫较觉角校蕉椒礁焦胶交郊浇骄娇嚼搅铰矫侥脚狡饺缴绞剿教酵轿窖佼僬艽茭挢噍峤徼姣敫皎鹪蛟醮跤鲛" };
const wchar_t PY_mb_jie[] = { L"洁结解姐戒揭杰接皆界借介捷睫秸街阶截劫节桔竭藉芥疥诫届偈讦诘卩拮喈嗟婕孑桀碣锴疖颉蚧羯鲒骱" };
const wchar_t PY_mb_jin[] = { L"巾尽筋斤金今津紧锦仅谨进靳晋禁近烬浸劲襟卺荩堇噤馑廑妗缙瑾槿赆觐钅衿矜" };
const wchar_t PY_mb_jing[] = { L"京惊精经井睛晶景净颈静境敬警镜径竟竞劲荆兢茎鲸粳痉靖刭儆阱陉菁獍憬泾迳弪婧肼胫腈旌靓" };
const wchar_t PY_mb_jiong[] = { L"炯窘冂迥扃" };
const wchar_t PY_mb_jiu[] = { L"九就救揪究纠玖韭久灸酒旧臼舅咎疚厩僦啾阄柩桕鸠鹫赳鬏" };
const wchar_t PY_mb_ju[] = { L"巨具距俱句惧车柜剧居驹菊局咀矩举沮聚拒据踞锯炬鞠拘狙疽倨讵苣苴莒掬遽屦琚枸椐榘榉橘犋飓钜锔窭裾趄醵踽龃雎瞿鞫" };
const wchar_t PY_mb_juan[] = { L"眷卷捐鹃娟倦绢圈鄄狷涓桊蠲锩镌隽" };
const wchar_t PY_mb_jue[] = { L"决诀绝觉角掘倔嚼脚撅攫抉爵厥劂谲矍堀蕨噘崛獗孓珏桷橛爝镢蹶觖" };
const wchar_t PY_mb_jun[] = { L"军君均菌钧峻俊竣浚郡骏龟捃皲筠麇" };
const wchar_t PY_mb_ka[] = { L"卡喀咖咯佧咔胩" };
const wchar_t PY_mb_kai[] = { L"开揩楷凯慨剀垲蒈忾恺铠锎锴" };
const wchar_t PY_mb_kan[] = { L"看刊堪勘坎砍侃龛瞰凵莰阚槛戡" };
const wchar_t PY_mb_kang[] = { L"康慷糠扛抗亢炕伉闶钪" };
const wchar_t PY_mb_kao[] = { L"考靠拷烤栲犒铐尻" };
const wchar_t PY_mb_ke[] = { L"可渴克科刻客课嗑坷苛柯棵磕颗壳咳恪蝌岢溘稞骒缂珂轲氪瞌钶铪呵锞疴窠颏蚵髁" };
const wchar_t PY_mb_ken[] = { L"肯啃垦恳裉" };
const wchar_t PY_mb_keng[] = { L"坑吭铿胫铒" };
const wchar_t PY_mb_kong[] = { L"空恐孔控倥崆箜" };
const wchar_t PY_mb_kou[] = { L"抠口扣寇芤蔻叩眍筘" };
const wchar_t PY_mb_ku[] = { L"枯哭窟苦酷库裤绔骷刳堀喾" };
const wchar_t PY_mb_kua[] = { L"夸垮挎跨胯侉锞" };
const wchar_t PY_mb_kuai[] = { L"会块筷侩快蒯郐哙狯脍" };
const wchar_t PY_mb_kuan[] = { L"宽款髋" };
const wchar_t PY_mb_kuang[] = { L"况匡筐狂框矿眶旷诓诳邝圹夼哐纩贶" };
const wchar_t PY_mb_kui[] = { L"亏盔岿窥葵奎魁傀馈愧溃馗匮逵睽跬夔隗蒉揆喹喟悝愦暌聩蝰篑" };
const wchar_t PY_mb_kun[] = { L"坤昆捆困悃琨锟醌鲲阃髡" };
const wchar_t PY_mb_kuo[] = { L"括扩廓阔蛞" };
const wchar_t PY_mb_la[] = { L"垃拉喇蜡腊辣啦落剌邋旯砬瘌" };
const wchar_t PY_mb_lai[] = { L"莱来赖崃徕涞濑赉睐癞籁铼" };
const wchar_t PY_mb_lan[] = { L"蓝婪栏拦篮阑兰澜谰揽览懒缆烂滥岚漤榄斓镧褴罱" };
const wchar_t PY_mb_lang[] = { L"郎朗浪琅榔狼廊啷阆螂锒蒗稂莨" };
const wchar_t PY_mb_lao[] = { L"捞劳牢老佬姥酪烙涝落络唠崂醪栳铑铹痨耢" };
const wchar_t PY_mb_le[] = { L"勒乐了仂叻泐鳓" };
const wchar_t PY_mb_lei[] = { L"累勒雷镭蕾磊儡垒擂肋类泪羸诔嘞嫘缧檑耒酹" };
const wchar_t PY_mb_leng[] = { L"棱楞冷塄愣" };
const wchar_t PY_mb_li[] = { L"利力历厉立粒礼沥吏理李里厘励丽梨犁隶黎篱离漓鲤栗砾莉荔狸傈例俐痢璃哩鬲俪俚郦坜苈莅蓠藜呖唳喱猁溧澧逦娌嫠骊缡枥栎轹戾砺砬詈罹锂鹂疠疬蛎蜊蠡笠篥粝醴跞雳鲡鳢黧" };
const wchar_t PY_mb_lia[] = { L"俩" };
const wchar_t PY_mb_lian[] = { L"联莲连廉怜涟帘敛脸链恋炼练潋镰濂琏楝奁殓蔹臁裢裣蠊鲢" };
const wchar_t PY_mb_liang[] = { L"两亮俩粮凉梁粱良辆量晾谅墚莨椋踉魉" };
const wchar_t PY_mb_liao[] = { L"了撩料聊僚疗燎寥辽潦撂镣廖蓼尥嘹獠寮缭钌鹩" };
const wchar_t PY_mb_lie[] = { L"列裂烈劣洌猎冽埒捩咧趔躐鬣" };
const wchar_t PY_mb_lin[] = { L"临邻赁拎琳林磷霖鳞淋凛吝蔺啉嶙廪懔遴檩辚膦瞵粼躏麟" };
const wchar_t PY_mb_ling[] = { L"令灵另棱玲菱零龄铃伶羚凌陵岭聆领酃苓呤囹泠绫柃棂瓴蛉翎鲮" };
const wchar_t PY_mb_liu[] = { L"刘六溜琉榴硫馏留瘤流柳碌陆浏遛骝绺旒熘锍镏鹨鎏" };
const wchar_t PY_mb_lo[] = { L"咯" };
const wchar_t PY_mb_long[] = { L"龙弄聋咙笼窿隆垄拢陇垅茏泷珑栊胧砻癃" };
const wchar_t PY_mb_lou[] = { L"楼娄搂篓漏陋露偻蒌喽嵝镂瘘耧蝼髅" };
const wchar_t PY_mb_lu[] = { L"六芦卢颅庐炉掳卤虏鲁麓碌露路赂鹿潞禄录陆戮绿垆撸噜泸渌漉逯璐栌橹轳辂辘贲氇胪镥鸬鹭簏舻鲈" };
const wchar_t PY_mb_lv[] = { L"滤率绿吕铝侣旅履屡缕虑氯律驴褛偻捋闾榈膂稆" };
const wchar_t PY_mb_luan[] = { L"乱孪峦挛滦卵" };
const wchar_t PY_mb_lue[] = { L"掠略锊" };
const wchar_t PY_mb_lun[] = { L"仑抡轮伦沦纶论囵" };
const wchar_t PY_mb_luo[] = { L"落罗铬咯烙萝螺逻锣箩骡裸洛骆络倮蠃荦捋摞猡泺漯珞椤脶硌镙瘰雒" };
const wchar_t PY_mb_m[] = { L"呒" };
const wchar_t PY_mb_ma[] = { L"妈麻玛码蚂马骂嘛吗摩抹唛犸嬷杩蟆" };
const wchar_t PY_mb_mai[] = { L"埋瞒馒蛮满蔓曼慢漫谩墁幔缦熳镘颟螨鳗鞔" };
const wchar_t PY_mb_man[] = { L"蛮馒瞒满曼谩慢漫蔓" };
const wchar_t PY_mb_mang[] = { L"芒茫盲氓忙莽邙漭硭蟒" };
const wchar_t PY_mb_mao[] = { L"猫茅锚毛矛髦卯茂冒帽貌贸袤铆茆峁泖瑁昴牦耄旄懋瞀蝥蟊" };
const wchar_t PY_mb_me[] = { L"么" };
const wchar_t PY_mb_mei[] = { L"每妹美玫枚昧寐袂魅梅酶霉煤没眉媒镁媚莓嵋猸浼湄楣镅鹛" };
const wchar_t PY_mb_men[] = { L"门闷们扪焖懑钔" };
const wchar_t PY_mb_meng[] = { L"萌梦蒙檬盟锰猛孟勐甍瞢懵朦礞虻蜢蠓艋艨" };
const wchar_t PY_mb_mi[] = { L"眯醚靡糜迷谜弥米秘觅泌蜜密麋谧幂芈冖蘼咪嘧猕汨宓弭纟脒祢敉糸縻" };
const wchar_t PY_mb_mian[] = { L"面棉眠绵冕免勉娩缅沔渑湎宀腼眄" };
const wchar_t PY_mb_miao[] = { L"苗描瞄藐秒渺庙妙喵邈缈缪杪淼眇鹋" };
const wchar_t PY_mb_mie[] = { L"蔑灭乜咩篾蠛" };
const wchar_t PY_mb_min[] = { L"民抿皿敏悯闽苠岷闵泯缗玟珉愍黾鳘" };
const wchar_t PY_mb_ming[] = { L"明螟鸣铭名命冥茗溟暝瞑酩" };
const wchar_t PY_mb_miu[] = { L"谬缪" };
const wchar_t PY_mb_mo[] = { L"摸摹蘑模膜磨摩魔抹末莫墨默沫漠寞陌脉没麽万谟茉蓦馍嫫殁镆秣瘼耱貊貘" };
const wchar_t PY_mb_mou[] = { L"谋牟某侔哞缪眸蛑鍪" };
const wchar_t PY_mb_mu[] = { L"木目睦模牟拇牡亩姆母墓暮幕募慕牧穆苜沐仫坶毪钼" };
const wchar_t PY_mb_na[] = { L"拿哪呐钠那娜纳捺肭镎衲" };
const wchar_t PY_mb_nai[] = { L"氖乃奶耐奈鼐佴艿萘柰" };
const wchar_t PY_mb_nan[] = { L"南男难喃囡楠腩蝻赧" };
const wchar_t PY_mb_nang[] = { L"囊囔馕攮曩" };
const wchar_t PY_mb_nao[] = { L"挠脑恼闹淖孬垴呶猱瑙硇铙蛲" };
const wchar_t PY_mb_ne[] = { L"哪呢讷" };
const wchar_t PY_mb_nei[] = { L"内馁" };
const wchar_t PY_mb_nen[] = { L"嫩恁" };
const wchar_t PY_mb_neng[] = { L"能" };
const wchar_t PY_mb_ng[] = { L"嗯" };
const wchar_t PY_mb_ni[] = { L"你呢拟尼妮霓倪泥匿腻逆溺伲坭猊怩昵旎祢慝睨铌鲵" };
const wchar_t PY_mb_nian[] = { L"蔫拈年碾撵捻念廿埝辇黏鲇鲶" };
const wchar_t PY_mb_niang[] = { L"娘酿" };
const wchar_t PY_mb_niao[] = { L"鸟尿脲袅茑嬲" };
const wchar_t PY_mb_nie[] = { L"捏聂孽啮镊镍涅蹑蘖嗫乜陧颞臬" };
const wchar_t PY_mb_nin[] = { L"您" };
const wchar_t PY_mb_ning[] = { L"柠狞凝宁拧泞佞咛甯聍" };
const wchar_t PY_mb_niu[] = { L"牛扭钮纽拗妞狃忸" };
const wchar_t PY_mb_nong[] = { L"脓浓农弄侬哝" };
const wchar_t PY_mb_nou[] = { L"耨" };
const wchar_t PY_mb_nu[] = { L"奴努怒弩胬孥驽" };
const wchar_t PY_mb_nuan[] = { L"暖" };
const wchar_t PY_mb_nue[] = { L"疟虐" };
const wchar_t PY_mb_nuo[] = { L"娜挪懦糯诺傩搦喏锘" };
const wchar_t PY_mb_nv[] = { L"女恧钕衄" };
const wchar_t PY_mb_o[] = { L"哦喔噢" };
const wchar_t PY_mb_ou[] = { L"欧鸥殴藕呕偶沤区讴怄瓯耦" };
const wchar_t PY_mb_pa[] = { L"扒耙啪趴爬帕怕琶葩杷筢" };
const wchar_t PY_mb_pai[] = { L"拍排牌徘湃派迫俳蒎哌" };
const wchar_t PY_mb_pan[] = { L"番攀潘盘磐盼畔判叛蟠蹒胖拚丬爿泮贲袢襻" };
const wchar_t PY_mb_pang[] = { L"膀磅镑乓庞旁耪胖彷滂螃逄" };
const wchar_t PY_mb_pao[] = { L"抛咆刨炮袍跑泡狍庖疱脬匏" };
const wchar_t PY_mb_pei[] = { L"呸胚培裴赔陪配佩沛辔霈帔旆锫醅" };
const wchar_t PY_mb_pen[] = { L"喷盆湓" };
const wchar_t PY_mb_peng[] = { L"捧碰砰抨烹澎彭蓬棚硼篷膨朋鹏怦堋嘭蟛" };
const wchar_t PY_mb_pi[] = { L"辟否坯砒霹批披劈琵毗啤脾疲皮匹痞僻丕屁譬癖貔仳陂陴邳郫圮埤鼙芘擗噼庀淠媲纰枇甓睥罴铍裨疋蚍蜱" };
const wchar_t PY_mb_pian[] = { L"扁便篇偏片骗谝骈缏犏胼翩蹁" };
const wchar_t PY_mb_piao[] = { L"飘漂瓢票朴剽嫖缥瞟嘌骠殍螵" };
const wchar_t PY_mb_pie[] = { L"撇瞥丿苤氕" };
const wchar_t PY_mb_pin[] = { L"拼频贫品聘姘嫔榀牝颦" };
const wchar_t PY_mb_ping[] = { L"冯乒坪苹萍平凭瓶评屏俜娉枰鲆" };
const wchar_t PY_mb_po[] = { L"泊繁坡泼颇婆破魄迫粕朴叵陂鄱珀攴攵钋钷皤笸" };
const wchar_t PY_mb_pou[] = { L"剖裒掊" };
const wchar_t PY_mb_pu[] = { L"普堡暴脯扑铺仆莆葡菩蒲埔朴圃浦谱曝瀑匍噗溥蹼濮璞氆镤镨" };
const wchar_t PY_mb_qi[] = { L"七起妻乞企启稽缉期欺栖戚凄漆柒沏其棋奇歧畦崎脐齐旗祈岐祁骑岂琪琦杞契砌器气迄弃汽泣讫亟祺憩蹊鳍麒亓俟圻芑芪荠萋葺淇骐绮耆蕲桤槭欹嘁屺汔碛颀蛴蜞綦綮" };
const wchar_t PY_mb_qia[] = { L"卡掐恰洽葜袷髂" };
const wchar_t PY_mb_qian[] = { L"牵扦钎铅千迁签仟谦乾黔钱钳前潜遣浅谴堑嵌欠歉纤倩佥阡芊芡茜荨掮岍悭慊骞搴褰缱椠犍肷愆钤虔箝羟" };
const wchar_t PY_mb_qiang[] = { L"枪呛腔羌墙蔷强抢跄戕戗炝锵镪丬襁嫱樯蜣羟" };
const wchar_t PY_mb_qiao[] = { L"壳橇锹敲悄桥瞧乔侨巧鞘撬翘峭俏窍雀诮谯荞峤憔樵跷鞒缲劁愀硗铫" };
const wchar_t PY_mb_qie[] = { L"切茄且怯窃伽惬慊妾趄郄挈锲箧" };
const wchar_t PY_mb_qin[] = { L"钦侵亲秦琴勤芹擒禽寝沁芩揿衾吣嗪噙廑檎锓矜覃螓" };
const wchar_t PY_mb_qing[] = { L"亲青轻氢倾卿清擎晴氰情顷请庆磬苘圊檠锖蜻罄箐綮謦鲭黥" };
const wchar_t PY_mb_qiong[] = { L"琼穷穹蛩邛茕筇跫銎" };
const wchar_t PY_mb_qiu[] = { L"仇龟秋丘邱球求囚酋泅俅逑裘糗遒巯犰湫楸赇虬蚯蝤鳅" };
const wchar_t PY_mb_qu[] = { L"趋区蛆曲躯屈驱渠取娶龋趣去蛐黢戌诎劬凵苣蕖蘧岖衢阒璩觑氍朐祛磲鸲癯蠼麴瞿" };
const wchar_t PY_mb_quan[] = { L"圈颧权醛泉全痊拳犬券劝诠荃蜷鬈犭悛绻辁畎铨筌" };
const wchar_t PY_mb_que[] = { L"缺炔瘸却鹊榷确雀阕阙悫" };
const wchar_t PY_mb_qui[] = { L"鼽" };
const wchar_t PY_mb_qun[] = { L"裙群逡麇" };
const wchar_t PY_mb_ran[] = { L"然燃冉染苒蚺髯" };
const wchar_t PY_mb_rang[] = { L"瓤壤攘嚷让禳穰" };
const wchar_t PY_mb_rao[] = { L"饶扰绕荛娆桡" };
const wchar_t PY_mb_re[] = { L"惹热喏" };
const wchar_t PY_mb_ren[] = { L"壬仁人忍韧任认刃妊纫稔亻仞荏葚饪轫衽" };
const wchar_t PY_mb_reng[] = { L"扔仍" };
const wchar_t PY_mb_ri[] = { L"日" };
const wchar_t PY_mb_rong[] = { L"戎茸蓉荣融熔溶容绒冗嵘狨榕肜蝾" };
const wchar_t PY_mb_rou[] = { L"揉柔肉糅蹂鞣" };
const wchar_t PY_mb_ru[] = { L"茹蠕儒孺如辱乳汝入濡褥溽蓐嚅薷洳缛铷襦颥" };
const wchar_t PY_mb_ruan[] = { L"软阮朊" };
const wchar_t PY_mb_rui[] = { L"蕊瑞锐芮睿枘蕤蚋" };
const wchar_t PY_mb_run[] = { L"闰润" };
const wchar_t PY_mb_ruo[] = { L"若弱偌箬" };
const wchar_t PY_mb_sa[] = { L"撒洒萨卅仨飒脎" };
const wchar_t PY_mb_sai[] = { L"腮鳃塞赛噻" };
const wchar_t PY_mb_san[] = { L"三叁伞散馓毵糁" };
const wchar_t PY_mb_sang[] = { L"桑嗓丧搡磉颡" };
const wchar_t PY_mb_sao[] = { L"搔骚扫嫂臊瘙埽缫鳋" };
const wchar_t PY_mb_se[] = { L"塞瑟色涩啬铯穑" };
const wchar_t PY_mb_sen[] = { L"森" };
const wchar_t PY_mb_seng[] = { L"僧" };
const wchar_t PY_mb_sha[] = { L"莎砂杀刹沙纱傻啥煞杉厦痧裟霎鲨唼歃铩" };
const wchar_t PY_mb_shai[] = { L"色筛晒" };
const wchar_t PY_mb_shan[] = { L"掺单珊苫杉山删煽衫闪陕擅赡膳善汕扇缮栅讪疝舢蟮跚鳝剡鄯埏芟彡潸姗嬗骟膻禅钐髟" };
const wchar_t PY_mb_shang[] = { L"墒伤商赏晌上尚裳绱殇觞垧熵" };
const wchar_t PY_mb_shao[] = { L"鞘梢捎稍烧芍勺韶少哨邵绍劭苕艄潲杓蛸筲" };
const wchar_t PY_mb_she[] = { L"奢赊蛇舌舍赦摄射慑涉社设麝折厍佘揲猞滠歙畲铊" };
const wchar_t PY_mb_shei[] = { L"谁" };
const wchar_t PY_mb_shen[] = { L"什参砷申呻伸身深娠绅神沈审婶甚肾慎渗诜谂莘葚哂渖椹胂矧蜃" };
const wchar_t PY_mb_sheng[] = { L"乘声生甥牲升绳省盛剩胜圣笙嵊渑晟眚" };
const wchar_t PY_mb_shi[] = { L"是事匙师十石失狮施湿诗尸虱拾时什食蚀实识史矢使屎驶始式示士世柿拭誓逝势嗜噬适仕侍释饰氏市恃室视试似弑舐殖峙谥埘莳蓍饣轼贳炻礻铈铊螫筮酾豕鲥鲺" };
const wchar_t PY_mb_shou[] = { L"收手首守寿授售受瘦兽扌狩绶艏" };
const wchar_t PY_mb_shu[] = { L"蔬枢梳殊抒输叔舒淑疏书赎孰熟薯暑曙署蜀黍鼠属术述树束戍竖墅庶数漱恕倏塾沭澍姝丨菽摅纾毹腧殳镯秫疋" };
const wchar_t PY_mb_shua[] = { L"刷耍唰" };
const wchar_t PY_mb_shuai[] = { L"率摔衰甩帅蟀" };
const wchar_t PY_mb_shuan[] = { L"栓拴闩涮" };
const wchar_t PY_mb_shuang[] = { L"霜双爽泷孀" };
const wchar_t PY_mb_shui[] = { L"水睡税说氵" };
const wchar_t PY_mb_shun[] = { L"吮瞬顺舜" };
const wchar_t PY_mb_shuo[] = { L"数说硕朔烁蒴搠妁槊铄" };
const wchar_t PY_mb_si[] = { L"斯撕嘶思私司丝死肆寺嗣四伺似饲巳厮咝俟兕厶饣汜泗澌姒驷缌祀锶鸶耜蛳笥" };
const wchar_t PY_mb_song[] = { L"松耸怂颂送宋讼诵嵩忪悚淞竦崧菘凇" };
const wchar_t PY_mb_sou[] = { L"搜艘擞嗽叟嗖馊溲飕瞍锼螋嗾薮" };
const wchar_t PY_mb_su[] = { L"苏酥俗素速粟僳塑溯宿诉肃缩夙愫涑簌稣谡蔌嗉觫" };
const wchar_t PY_mb_suan[] = { L"酸蒜算狻" };
const wchar_t PY_mb_sui[] = { L"虽岁绥隋随髓祟遂碎隧穗" };
const wchar_t PY_mb_sun[] = { L"孙损笋" };
const wchar_t PY_mb_suo[] = { L"蓑梭唆缩琐索锁所唢嗦嗍娑莎桫挲睃羧" };
const wchar_t PY_mb_ta[] = { L"塌他它她塔獭挞沓蹋踏拓闼遢榻铊趿溻鳎漯" };
const wchar_t PY_mb_tai[] = { L"胎苔抬台泰酞太态汰跆邰薹骀肽炱钛鲐" };
const wchar_t PY_mb_tan[] = { L"弹坍摊贪瘫滩坛檀痰潭谭谈坦毯袒碳探叹炭覃郯澹昙赕忐钽锬镡" };
const wchar_t PY_mb_tang[] = { L"汤塘搪堂棠膛唐糖倘躺淌趟烫傥饧溏瑭樘铛螳铴镗耥螗羰醣帑" };
const wchar_t PY_mb_tao[] = { L"掏涛滔绦萄桃逃淘陶讨套叨啕饕洮韬焘鼗" };
const wchar_t PY_mb_te[] = { L"特忒忑铽" };
const wchar_t PY_mb_teng[] = { L"藤腾疼滕誊" };
const wchar_t PY_mb_ti[] = { L"梯剔踢锑提题蹄啼体替嚏惕涕剃屉倜悌缇荑逖绨鹈裼醍" };
const wchar_t PY_mb_tian[] = { L"天添填田甜恬舔腆殄掭忝阗畋钿锘" };
const wchar_t PY_mb_tiao[] = { L"调挑条迢眺跳佻髫苕祧铫窕蜩笤粜龆鲦" };
const wchar_t PY_mb_tie[] = { L"贴铁帖餮锇萜" };
const wchar_t PY_mb_ting[] = { L"厅听烃汀廷停亭庭挺艇莛葶婷铤蜓霆梃" };
const wchar_t PY_mb_tong[] = { L"桐瞳同铜彤童桶捅筒统痛佟僮茼恸潼酮仝垌嗵峒砼" };
const wchar_t PY_mb_tou[] = { L"偷投头透骰钭亠" };
const wchar_t PY_mb_tu[] = { L"凸秃突图徒途涂屠土吐兔堍荼菟钍酴" };
const wchar_t PY_mb_tuan[] = { L"湍团抟彖疃" };
const wchar_t PY_mb_tui[] = { L"推颓腿蜕褪退煺" };
const wchar_t PY_mb_tun[] = { L"囤褪吞屯臀饨豚氽暾" };
const wchar_t PY_mb_tuo[] = { L"说拖拓托脱鸵陀驮驼椭妥唾跎乇佗坨沱柝柁橐砣铊鼍箨酡庹" };
const wchar_t PY_mb_wa[] = { L"挖哇蛙洼娃瓦袜佤娲腽" };
const wchar_t PY_mb_wai[] = { L"歪外崴" };
const wchar_t PY_mb_wan[] = { L"蔓豌弯湾玩顽丸烷完碗挽晚皖惋宛婉万腕剜芄莞菀纨蜿绾琬脘畹鞔" };
const wchar_t PY_mb_wang[] = { L"汪王亡枉网往旺望忘妄罔惘魍尢辋" };
const wchar_t PY_mb_wei[] = { L"为位谓威巍微危韦维违桅围唯惟潍苇萎委伟伪尾纬未蔚味畏胃喂魏渭尉慰卫偎诿隗圩葳薇帏帷崴嵬猬逶娓痿炜玮闱猥隈沩洧涠韪軎煨艉鲔囗" };
const wchar_t PY_mb_wen[] = { L"问文闻纹瘟温蚊吻稳紊刎雯玟阌汶璺" };
const wchar_t PY_mb_weng[] = { L"嗡翁瓮蓊蕹" };
const wchar_t PY_mb_wo[] = { L"我握喔蜗涡窝斡卧沃挝倭莴幄龌渥肟硪" };
const wchar_t PY_mb_wu[] = { L"五物勿务午舞伍武侮恶悟误兀巫雾呜钨乌污诬屋无芜梧吾吴毋捂坞戊晤仵邬鹉圬芴唔庑怃忤鹜痦蜈浯寤迕妩婺骛阢杌牾於焐鋈鼯" };
const wchar_t PY_mb_xi[] = { L"希习夕戏细昔熙析西硒矽晰嘻吸锡牺稀蹊息悉膝惜熄溪汐犀袭席媳喜洗系隙羲皙屣嬉玺樨奚茜檄烯铣匚僖兮隰郗菥葸蓰唏徙饩阋浠淅曦觋欷歙熹禊禧穸裼蜥螅蟋舄舾粞翕醯鼷" };
const wchar_t PY_mb_xia[] = { L"瞎虾匣霞辖暇峡侠狭下厦夏吓呷狎遐瑕柙硖罅黠" };
const wchar_t PY_mb_xian[] = { L"现先仙嫌显险献县贤铣洗掀锨鲜纤咸衔舷闲涎弦腺馅羡宪陷限线冼苋莶藓岘猃暹娴氙燹祆鹇痃痫蚬筅籼酰跣跹霰" };
const wchar_t PY_mb_xiang[] = { L"像向象降相厢镶香箱湘乡翔祥详想响享项巷橡襄飨芗葙饷庠骧缃蟓鲞" };
const wchar_t PY_mb_xiao[] = { L"小消肖萧硝霄削哮嚣销宵淆晓孝校啸笑效哓潇逍筱箫骁绡枭枵蛸魈" };
const wchar_t PY_mb_xie[] = { L"些歇蝎鞋协挟携邪斜胁谐写械卸蟹懈泄泻谢屑血解楔叶偕亵勰燮薤撷獬廨渫瀣邂绁缬榭榍颉躞鲑骱" };
const wchar_t PY_mb_xin[] = { L"薪芯锌欣辛新忻心信衅馨莘歆鑫昕囟忄镡" };
const wchar_t PY_mb_xing[] = { L"幸省星腥猩惺兴刑型形邢行醒杏性姓饧陉荇荥擤悻硎" };
const wchar_t PY_mb_xiong[] = { L"兄凶胸匈汹雄熊芎" };
const wchar_t PY_mb_xiu[] = { L"臭宿休修羞朽嗅锈秀袖绣咻溴貅馐岫庥鸺髹" };
const wchar_t PY_mb_xu[] = { L"续绪墟戌需虚嘘须徐许蓄酗叙旭序畜恤絮婿诩煦勖圩蓿洫浒溆顼栩吁胥盱糈醑" };
const wchar_t PY_mb_xuan[] = { L"玄选轩喧宣渲悬旋暄绚炫眩癣儇谖萱泫漩璇楦煊揎碹铉镟券" };
const wchar_t PY_mb_xue[] = { L"削靴薛学穴雪血鳕谑噱泶踅" };
const wchar_t PY_mb_xun[] = { L"寻旬迅讯询训勋熏循驯巡殉汛逊郇埙荀薰峋徇醺鲟浚荨蕈獯巽恂洵浔曛窨" };
const wchar_t PY_mb_ya[] = { L"牙芽亚哑压雅押鸦鸭呀丫崖衙涯讶轧伢蚜垭揠岈迓娅琊桠氩砑睚痖疋" };
const wchar_t PY_mb_yan[] = { L"言演验厌严沿炎燕咽阉奄掩眼烟淹盐研岩延颜阎衍艳堰砚雁唁焉彦焰宴谚蜒闫妍嫣胭腌焱恹俨偃铅殷厣赝剡兖讠谳阽郾鄢芫菸崦魇阏湮滟琰檐晏罨筵酽餍鼹鼽" };
const wchar_t PY_mb_yang[] = { L"央仰羊洋阳养样杨扬恙殃鸯秧佯氧疡痒漾徉怏泱炀烊蛘鞅" };
const wchar_t PY_mb_yao[] = { L"要邀咬药腰妖摇尧肴窈遥窑谣姚舀耀钥夭爻幺吆瑶啮疟侥崤崾徭珧杳轺曜铫鹞繇鳐" };
const wchar_t PY_mb_ye[] = { L"也页业叶夜液椰噎耶爷野冶掖曳腋邪咽谒盅靥邺揶琊晔烨铘" };
const wchar_t PY_mb_yi[] = { L"一乙已以忆义议谊译异益壹医揖铱依伊衣颐夷遗移仪胰疑沂宜姨彝椅蚁倚矣艺抑易邑屹亿役臆逸肄疫亦裔意毅溢诣翼翌艾尾绎刈劓佚佾诒阝圯埸懿苡荑薏弈奕挹弋呓咦咿噫峄嶷猗饴怿怡悒漪迤驿缢殪轶贻欹旖熠眙钇铊镒镱痍瘗癔翊衤蜴舣羿翳酏黟" };
const wchar_t PY_mb_yin[] = { L"尹引印茵荫因殷音阴姻吟银淫寅饮隐龈胤蚓鄞廴垠堙茚吲喑狺夤洇湮氤铟瘾窨霪" };
const wchar_t PY_mb_ying[] = { L"映影英莹萤营荧樱婴鹰应缨蝇迎赢盈颖硬嬴莺萦鹦潆瀛滢瑛郢茔荥蓥撄嘤膺璎楹媵瘿颍罂" };
const wchar_t PY_mb_yo[] = { L"哟育唷" };
const wchar_t PY_mb_yong[] = { L"用拥佣勇涌臃痈庸雍踊蛹咏泳永恿俑壅墉喁慵邕镛甬鳙饔" };
const wchar_t PY_mb_you[] = { L"尤有又诱幼友右佑幽优悠忧由邮铀犹油游酉釉呦疣鱿黝鼬蚰攸卣侑莠莜莸尢囿宥柚猷牖铕蚴蝣蝤繇" };
const wchar_t PY_mb_yu[] = { L"余与于予宇玉雨育誉浴鱼迂淤盂虞愚舆俞逾愉渝渔隅娱屿禹语羽域芋郁吁遇喻峪御愈榆欲狱寓裕预豫驭竽毓谀於谕蔚尉禺伛俣萸菀蓣揄圄圉嵛狳饫馀庾阈鬻妪妤纡瑜昱觎腴欤煜熨燠肀聿钰鹆鹬瘐瘀窬窳蜮蝓臾舁雩龉" };
const wchar_t PY_mb_yuan[] = { L"原元园员圆源缘远愿怨院鸳渊冤垣袁援辕猿苑媛塬芫掾圜沅瑗橼爰眢鸢螈箢鼋" };
const wchar_t PY_mb_yue[] = { L"月悦阅乐说曰约越跃钥岳粤龠哕瀹栎樾刖钺" };
const wchar_t PY_mb_yun[] = { L"云员允运晕耘匀陨蕴酝熨韵孕氲殒芸郧郓狁恽愠纭韫昀筠" };
const wchar_t PY_mb_za[] = { L"匝砸杂扎咋咂拶" };
const wchar_t PY_mb_zai[] = { L"再在栽哉灾宰载崽甾" };
const wchar_t PY_mb_zan[] = { L"咱攒暂赞昝簪拶瓒糌趱錾" };
const wchar_t PY_mb_zang[] = { L"藏赃脏葬驵臧" };
const wchar_t PY_mb_zao[] = { L"枣遭早造皂灶糟凿澡躁噪燥藻蚤唣" };
const wchar_t PY_mb_ze[] = { L"责择则泽咋仄赜啧帻迮昃笮箦舴" };
const wchar_t PY_mb_zei[] = { L"贼" };
const wchar_t PY_mb_zen[] = { L"怎谮" };
const wchar_t PY_mb_zeng[] = { L"增憎曾赠缯甑罾锃" };
const wchar_t PY_mb_zha[] = { L"扎闸查喳渣札轧铡眨栅榨咋乍炸诈吒咤柞揸蚱哳喋楂砟痄龃齄" };
const wchar_t PY_mb_zhai[] = { L"宅窄债翟择摘斋寨砦瘵" };
const wchar_t PY_mb_zhan[] = { L"占战站展沾绽瞻毡詹粘盏斩辗崭蘸颤栈湛谵搌骣旃" };
const wchar_t PY_mb_zhang[] = { L"张丈仗胀杖樟章彰漳掌涨帐账长瘴障幛嶂獐蟑仉鄣嫜璋" };
const wchar_t PY_mb_zhao[] = { L"找召爪着兆朝招昭诏沼赵照罩肇钊笊啁棹" };
const wchar_t PY_mb_zhe[] = { L"遮折哲蛰辙者锗蔗这浙着谪摺柘辄磔鹧褶蜇赭" };
const wchar_t PY_mb_zhen[] = { L"真贞针震振诊阵镇侦枕珍疹斟甄箴臻帧圳砧蓁浈溱缜桢椹榛轸赈胗朕祯畛稹鸩" };
const wchar_t PY_mb_zheng[] = { L"正证蒸挣睁征狰争怔整拯政症郑诤峥徵钲铮筝鲭" };
const wchar_t PY_mb_zhi[] = { L"只职识执值直植殖治支纸志址指质置制止至侄芝之汁旨枝知肢脂织趾挚掷致帜峙智秩稚吱蜘炙痔滞窒枳芷卮陟郅埴摭帙徵夂忮彘咫骘栉栀桎轵轾贽胝膣祉祗黹雉鸷痣蛭絷酯跖踬踯豸觯" };
const wchar_t PY_mb_zhong[] = { L"中众忠钟衷终种肿重仲盅冢忪锺螽舯踵" };
const wchar_t PY_mb_zhou[] = { L"舟周州洲诌粥轴肘帚咒皱宙昼骤荮啁妯纣绉胄碡籀繇酎" };
const wchar_t PY_mb_zhu[] = { L"主住注祝竹珠株蛛朱猪诸诛逐烛煮拄瞩嘱著柱助蛀贮铸筑驻伫竺箸侏属术邾苎茱洙渚潴杼槠橥炷铢疰瘃褚舳翥躅麈丶" };
const wchar_t PY_mb_zhua[] = { L"抓爪挝" };
const wchar_t PY_mb_zhuai[] = { L"拽转" };
const wchar_t PY_mb_zhuan[] = { L"传专砖转撰赚篆啭馔沌颛" };
const wchar_t PY_mb_zhuang[] = { L"幢桩庄装妆撞壮状奘戆" };
const wchar_t PY_mb_zhui[] = { L"椎锥追赘坠缀惴骓缒隹" };
const wchar_t PY_mb_zhun[] = { L"谆准饨肫窀" };
const wchar_t PY_mb_zhuo[] = { L"着捉拙卓桌灼茁浊酌琢啄倬诼擢浞涿濯焯禚斫镯" };
const wchar_t PY_mb_zi[] = { L"自子字仔兹咨资姿滋淄孜紫籽滓渍龇姊吱嵫谘茈孳缁梓辎赀恣眦锱秭耔笫粢趑觜訾鲻髭" };
const wchar_t PY_mb_zong[] = { L"宗综总鬃棕踪纵粽偬枞腙" };
const wchar_t PY_mb_zou[] = { L"走奏揍邹诹陬鄹驺鲰" };
const wchar_t PY_mb_zu[] = { L"足组卒族租祖诅阻俎菹镞" };
const wchar_t PY_mb_zuan[] = { L"钻攥纂缵躜" };
const wchar_t PY_mb_zui[] = { L"最罪嘴醉蕞觜" };
const wchar_t PY_mb_zun[] = { L"尊遵樽鳟撙" };
const wchar_t PY_mb_zuo[] = { L"左佐做作坐座昨撮唑柞阼琢嘬怍胙祚砟酢" };

const PinyinDef PinyinTable[] =
{
{"2","a",(wchar_t*)PY_mb_a},
{"3","e",(wchar_t*)PY_mb_e},
{"6","o",(wchar_t*)PY_mb_o},
{"24","ai",(wchar_t*)PY_mb_ai},
{"26","an",(wchar_t*)PY_mb_an},
{"26","ao",(wchar_t*)PY_mb_ao},
{"22","ba",(wchar_t*)PY_mb_ba},
{"24","bi",(wchar_t*)PY_mb_bi},
{"26","bo",(wchar_t*)PY_mb_bo},
{"28","bu",(wchar_t*)PY_mb_bu},
{"22","ca",(wchar_t*)PY_mb_ca},
{"23","ce",(wchar_t*)PY_mb_ce},
{"24","ci",(wchar_t*)PY_mb_ci},
{"28","cu",(wchar_t*)PY_mb_cu},
{"32","da",(wchar_t*)PY_mb_da},
{"33","de",(wchar_t*)PY_mb_de},
{"34","di",(wchar_t*)PY_mb_di},
{"38","du",(wchar_t*)PY_mb_du},
{"36","en",(wchar_t*)PY_mb_en},
{"37","er",(wchar_t*)PY_mb_er},
{"32","fa",(wchar_t*)PY_mb_fa},
{"36","fo",(wchar_t*)PY_mb_fo},
{"38","fu",(wchar_t*)PY_mb_fu},
{"42","ha",(wchar_t*)PY_mb_ha},
{"42","ga",(wchar_t*)PY_mb_ga},
{"43","ge",(wchar_t*)PY_mb_ge},
{"43","he",(wchar_t*)PY_mb_he},
{"48","gu",(wchar_t*)PY_mb_gu},
{"48","hu",(wchar_t*)PY_mb_hu},
{"54","ji",(wchar_t*)PY_mb_ji},
{"58","ju",(wchar_t*)PY_mb_ju},
{"52","ka",(wchar_t*)PY_mb_ka},
{"53","ke",(wchar_t*)PY_mb_ke},
{"58","ku",(wchar_t*)PY_mb_ku},
{"52","la",(wchar_t*)PY_mb_la},
{"53","le",(wchar_t*)PY_mb_le},
{"54","li",(wchar_t*)PY_mb_li},
{"58","lu",(wchar_t*)PY_mb_lu},
{"58","lv",(wchar_t*)PY_mb_lv},
{"62","ma",(wchar_t*)PY_mb_ma},
{"63","me",(wchar_t*)PY_mb_me},
{"64","mi",(wchar_t*)PY_mb_mi},
{"66","mo",(wchar_t*)PY_mb_mo},
{"68","mu",(wchar_t*)PY_mb_mu},
{"62","na",(wchar_t*)PY_mb_na},
{"63","ne",(wchar_t*)PY_mb_ne},
{"64","ni",(wchar_t*)PY_mb_ni},
{"68","nu",(wchar_t*)PY_mb_nu},
{"68","nv",(wchar_t*)PY_mb_nv},
{"68","ou",(wchar_t*)PY_mb_ou},
{"72","pa",(wchar_t*)PY_mb_pa},
{"74","pi",(wchar_t*)PY_mb_pi},
{"76","po",(wchar_t*)PY_mb_po},
{"78","pu",(wchar_t*)PY_mb_pu},
{"74","qi",(wchar_t*)PY_mb_qi},
{"78","qu",(wchar_t*)PY_mb_qu},
{"73","re",(wchar_t*)PY_mb_re},
{"74","ri",(wchar_t*)PY_mb_ri},
{"78","ru",(wchar_t*)PY_mb_ru},
{"72","sa",(wchar_t*)PY_mb_sa},
{"73","se",(wchar_t*)PY_mb_se},
{"74","si",(wchar_t*)PY_mb_si},
{"78","su",(wchar_t*)PY_mb_su},
{"82","ta",(wchar_t*)PY_mb_ta},
{"83","te",(wchar_t*)PY_mb_te},
{"84","ti",(wchar_t*)PY_mb_ti},
{"88","tu",(wchar_t*)PY_mb_tu},
{"92","wa",(wchar_t*)PY_mb_wa},
{"96","wo",(wchar_t*)PY_mb_wo},
{"98","wu",(wchar_t*)PY_mb_wu},
{"94","xi",(wchar_t*)PY_mb_xi},
{"98","xu",(wchar_t*)PY_mb_xu},
{"92","ya",(wchar_t*)PY_mb_ya},
{"93","ye",(wchar_t*)PY_mb_ye},
{"94","yi",(wchar_t*)PY_mb_yi},
{"96","yo",(wchar_t*)PY_mb_yo},
{"98","yu",(wchar_t*)PY_mb_yu},
{"92","za",(wchar_t*)PY_mb_za},
{"93","ze",(wchar_t*)PY_mb_ze},
{"94","zi",(wchar_t*)PY_mb_zi},
{"98","zu",(wchar_t*)PY_mb_zu},
{"264","ang",(wchar_t*)PY_mb_ang},
{"224","bai",(wchar_t*)PY_mb_bai},
{"226","ban",(wchar_t*)PY_mb_ban},
{"226","bao",(wchar_t*)PY_mb_bao},
{"234","bei",(wchar_t*)PY_mb_bei},
{"236","ben",(wchar_t*)PY_mb_ben},
{"243","bie",(wchar_t*)PY_mb_bie},
{"246","bin",(wchar_t*)PY_mb_bin},
{"224","cai",(wchar_t*)PY_mb_cai},
{"226","can",(wchar_t*)PY_mb_can},
{"226","cao",(wchar_t*)PY_mb_cao},
{"242","cha",(wchar_t*)PY_mb_cha},
{"243","che",(wchar_t*)PY_mb_che},
{"244","chi",(wchar_t*)PY_mb_chi},
{"248","chu",(wchar_t*)PY_mb_chu},
{"268","cou",(wchar_t*)PY_mb_cou},
{"284","cui",(wchar_t*)PY_mb_cui},
{"286","cun",(wchar_t*)PY_mb_cun},
{"286","cuo",(wchar_t*)PY_mb_cuo},
{"324","dai",(wchar_t*)PY_mb_dai},
{"326","dan",(wchar_t*)PY_mb_dan},
{"326","dao",(wchar_t*)PY_mb_dao},
{"334","dei",(wchar_t*)PY_mb_dei},
{"343","die",(wchar_t*)PY_mb_die},
{"348","diu",(wchar_t*)PY_mb_diu},
{"368","dou",(wchar_t*)PY_mb_dou},
{"384","dui",(wchar_t*)PY_mb_dui},
{"386","dun",(wchar_t*)PY_mb_dun},
{"386","duo",(wchar_t*)PY_mb_duo},
{"326","fan",(wchar_t*)PY_mb_fan},
{"334","fei",(wchar_t*)PY_mb_fei},
{"336","fen",(wchar_t*)PY_mb_fen},
{"368","fou",(wchar_t*)PY_mb_fou},
{"424","gai",(wchar_t*)PY_mb_gai},
{"426","gan",(wchar_t*)PY_mb_gan},
{"426","gao",(wchar_t*)PY_mb_gao},
{"434","gei",(wchar_t*)PY_mb_gei},
{"436","gen",(wchar_t*)PY_mb_gan},
{"468","gou",(wchar_t*)PY_mb_gou},
{"482","gua",(wchar_t*)PY_mb_gua},
{"484","gui",(wchar_t*)PY_mb_gui},
{"486","gun",(wchar_t*)PY_mb_gun},
{"486","guo",(wchar_t*)PY_mb_guo},
{"424","hai",(wchar_t*)PY_mb_hai},
{"426","han",(wchar_t*)PY_mb_han},
{"426","hao",(wchar_t*)PY_mb_hao},
{"434","hei",(wchar_t*)PY_mb_hei},
{"436","hen",(wchar_t*)PY_mb_hen},
{"468","hou",(wchar_t*)PY_mb_hou},
{"482","hua",(wchar_t*)PY_mb_hua},
{"484","hui",(wchar_t*)PY_mb_hui},
{"486","hun",(wchar_t*)PY_mb_hun},
{"486","huo",(wchar_t*)PY_mb_huo},
{"542","jia",(wchar_t*)PY_mb_jia},
{"543","jie",(wchar_t*)PY_mb_jie},
{"546","jin",(wchar_t*)PY_mb_jin},
{"548","jiu",(wchar_t*)PY_mb_jiu},
{"583","jue",(wchar_t*)PY_mb_jue},
{"586","jun",(wchar_t*)PY_mb_jun},
{"524","kai",(wchar_t*)PY_mb_kai},
{"526","kan",(wchar_t*)PY_mb_kan},
{"526","kao",(wchar_t*)PY_mb_kao},
{"536","ken",(wchar_t*)PY_mb_ken},
{"568","kou",(wchar_t*)PY_mb_kou},
{"582","kua",(wchar_t*)PY_mb_kua},
{"584","kui",(wchar_t*)PY_mb_kui},
{"586","kun",(wchar_t*)PY_mb_kun},
{"586","kuo",(wchar_t*)PY_mb_kuo},
{"524","lai",(wchar_t*)PY_mb_lai},
{"526","lan",(wchar_t*)PY_mb_lan},
{"526","lao",(wchar_t*)PY_mb_lao},
{"534","lei",(wchar_t*)PY_mb_lei},
{"543","lie",(wchar_t*)PY_mb_lie},
{"546","lin",(wchar_t*)PY_mb_lin},
{"548","liu",(wchar_t*)PY_mb_liu},
{"568","lou",(wchar_t*)PY_mb_lou},
{"583","lue",(wchar_t*)PY_mb_lue},
{"586","lun",(wchar_t*)PY_mb_lun},
{"586","luo",(wchar_t*)PY_mb_luo},
{"624","mai",(wchar_t*)PY_mb_mai},
{"626","man",(wchar_t*)PY_mb_man},
{"626","mao",(wchar_t*)PY_mb_mao},
{"634","mei",(wchar_t*)PY_mb_mei},
{"636","men",(wchar_t*)PY_mb_men},
{"643","mie",(wchar_t*)PY_mb_mie},
{"646","min",(wchar_t*)PY_mb_min},
{"648","miu",(wchar_t*)PY_mb_miu},
{"668","mou",(wchar_t*)PY_mb_mou},
{"624","nai",(wchar_t*)PY_mb_nai},
{"626","nan",(wchar_t*)PY_mb_nan},
{"626","nao",(wchar_t*)PY_mb_nao},
{"634","nei",(wchar_t*)PY_mb_nei},
{"636","nen",(wchar_t*)PY_mb_nen},
{"643","nie",(wchar_t*)PY_mb_nie},
{"646","nin",(wchar_t*)PY_mb_nin},
{"648","niu",(wchar_t*)PY_mb_niu},
{"683","nue",(wchar_t*)PY_mb_nue},
{"686","nuo",(wchar_t*)PY_mb_nuo},
{"724","pai",(wchar_t*)PY_mb_pai},
{"726","pan",(wchar_t*)PY_mb_pan},
{"726","pao",(wchar_t*)PY_mb_pao},
{"734","pei",(wchar_t*)PY_mb_pei},
{"736","pen",(wchar_t*)PY_mb_pen},
{"743","pie",(wchar_t*)PY_mb_pie},
{"746","pin",(wchar_t*)PY_mb_pin},
{"768","pou",(wchar_t*)PY_mb_pou},
{"742","qia",(wchar_t*)PY_mb_qia},
{"743","qie",(wchar_t*)PY_mb_qie},
{"746","qin",(wchar_t*)PY_mb_qin},
{"748","qiu",(wchar_t*)PY_mb_qiu},
{"783","que",(wchar_t*)PY_mb_que},
{"786","qun",(wchar_t*)PY_mb_qun},
{"726","ran",(wchar_t*)PY_mb_ran},
{"726","rao",(wchar_t*)PY_mb_rao},
{"736","ren",(wchar_t*)PY_mb_ren},
{"768","rou",(wchar_t*)PY_mb_rou},
{"784","rui",(wchar_t*)PY_mb_rui},
{"786","run",(wchar_t*)PY_mb_run},
{"786","ruo",(wchar_t*)PY_mb_ruo},
{"724","sai",(wchar_t*)PY_mb_sai},
{"726","sao",(wchar_t*)PY_mb_sao},
{"726","san",(wchar_t*)PY_mb_san},
{"736","sen",(wchar_t*)PY_mb_sen},
{"742","sha",(wchar_t*)PY_mb_sha},
{"743","she",(wchar_t*)PY_mb_she},
{"744","shi",(wchar_t*)PY_mb_shi},
{"748","shu",(wchar_t*)PY_mb_shu},
{"768","sou",(wchar_t*)PY_mb_sou},
{"784","sui",(wchar_t*)PY_mb_sui},
{"786","sun",(wchar_t*)PY_mb_sun},
{"786","suo",(wchar_t*)PY_mb_suo},
{"824","tai",(wchar_t*)PY_mb_tai},
{"826","tan",(wchar_t*)PY_mb_tan},
{"826","tao",(wchar_t*)PY_mb_tao},
{"843","tie",(wchar_t*)PY_mb_tie},
{"868","tou",(wchar_t*)PY_mb_tou},
{"884","tui",(wchar_t*)PY_mb_tui},
{"886","tun",(wchar_t*)PY_mb_tun},
{"886","tuo",(wchar_t*)PY_mb_tuo},
{"924","wai",(wchar_t*)PY_mb_wai},
{"926","wan",(wchar_t*)PY_mb_wan},
{"934","wei",(wchar_t*)PY_mb_wei},
{"936","wen",(wchar_t*)PY_mb_wen},
{"942","xia",(wchar_t*)PY_mb_xia},
{"943","xie",(wchar_t*)PY_mb_xie},
{"946","xin",(wchar_t*)PY_mb_xin},
{"948","xiu",(wchar_t*)PY_mb_xiu},
{"983","xue",(wchar_t*)PY_mb_xue},
{"986","xun",(wchar_t*)PY_mb_xun},
{"926","yan",(wchar_t*)PY_mb_yan},
{"926","yao",(wchar_t*)PY_mb_yao},
{"946","yin",(wchar_t*)PY_mb_yin},
{"968","you",(wchar_t*)PY_mb_you},
{"983","yue",(wchar_t*)PY_mb_yue},
{"986","yun",(wchar_t*)PY_mb_yun},
{"924","zai",(wchar_t*)PY_mb_zai},
{"926","zan",(wchar_t*)PY_mb_zan},
{"926","zao",(wchar_t*)PY_mb_zao},
{"934","zei",(wchar_t*)PY_mb_zei},
{"936","zen",(wchar_t*)PY_mb_zen},
{"942","zha",(wchar_t*)PY_mb_zha},
{"943","zhe",(wchar_t*)PY_mb_zhe},
{"944","zhi",(wchar_t*)PY_mb_zhi},
{"948","zhu",(wchar_t*)PY_mb_zhu},
{"968","zou",(wchar_t*)PY_mb_zou},
{"984","zui",(wchar_t*)PY_mb_zui},
{"986","zun",(wchar_t*)PY_mb_zun},
{"986","zuo",(wchar_t*)PY_mb_zuo},
{"2264","bang",(wchar_t*)PY_mb_bang},
{"2364","beng",(wchar_t*)PY_mb_beng},
{"2426","bian",(wchar_t*)PY_mb_bian},
{"2426","biao",(wchar_t*)PY_mb_biao},
{"2464","bing",(wchar_t*)PY_mb_bing},
{"2264","cang",(wchar_t*)PY_mb_cang},
{"2364","ceng",(wchar_t*)PY_mb_ceng},
{"2424","chai",(wchar_t*)PY_mb_chai},
{"2426","chan",(wchar_t*)PY_mb_chan},
{"2426","chao",(wchar_t*)PY_mb_chao},
{"2436","chen",(wchar_t*)PY_mb_chen},
{"2468","chou",(wchar_t*)PY_mb_chou},
{"2484","chuai",(wchar_t*)PY_mb_chuai},
{"2484","chui",(wchar_t*)PY_mb_chui},
{"2486","chun",(wchar_t*)PY_mb_chun},
{"2486","chuo",(wchar_t*)PY_mb_chuo},
{"2664","cong",(wchar_t*)PY_mb_cong},
{"2826","cuan",(wchar_t*)PY_mb_cuan},
{"3264","dang",(wchar_t*)PY_mb_dang},
{"3364","deng",(wchar_t*)PY_mb_deng},
{"3426","dian",(wchar_t*)PY_mb_dian},
{"3426","diao",(wchar_t*)PY_mb_diao},
{"3464","ding",(wchar_t*)PY_mb_ding},
{"3664","dong",(wchar_t*)PY_mb_dong},
{"3826","duan",(wchar_t*)PY_mb_duan},
{"3264","fang",(wchar_t*)PY_mb_fang},
{"3364","feng",(wchar_t*)PY_mb_feng},
{"4264","gang",(wchar_t*)PY_mb_gang},
{"4364","geng",(wchar_t*)PY_mb_geng},
{"4664","gong",(wchar_t*)PY_mb_gong},
{"4824","guai",(wchar_t*)PY_mb_guai},
{"4826","guan",(wchar_t*)PY_mb_guan},
{"4264","hang",(wchar_t*)PY_mb_hang},
{"4364","heng",(wchar_t*)PY_mb_heng},
{"4664","hong",(wchar_t*)PY_mb_hong},
{"4823","huai",(wchar_t*)PY_mb_huai},
{"4826","huan",(wchar_t*)PY_mb_huan},
{"5426","jian",(wchar_t*)PY_mb_jian},
{"5426","jiao",(wchar_t*)PY_mb_jiao},
{"5464","jing",(wchar_t*)PY_mb_jing},
{"5826","juan",(wchar_t*)PY_mb_juan},
{"5264","kang",(wchar_t*)PY_mb_kang},
{"5364","keng",(wchar_t*)PY_mb_keng},
{"5664","kong",(wchar_t*)PY_mb_kong},
{"5824","kuai",(wchar_t*)PY_mb_kuai},
{"5826","kuan",(wchar_t*)PY_mb_kuan},
{"5264","lang",(wchar_t*)PY_mb_lang},
{"5366","leng",(wchar_t*)PY_mb_leng},
{"5426","lian",(wchar_t*)PY_mb_lian},
{"5426","liao",(wchar_t*)PY_mb_liao},
{"5464","ling",(wchar_t*)PY_mb_ling},
{"5664","long",(wchar_t*)PY_mb_long},
{"5826","luan",(wchar_t*)PY_mb_luan},
{"6264","mang",(wchar_t*)PY_mb_mang},
{"6364","meng",(wchar_t*)PY_mb_meng},
{"6426","mian",(wchar_t*)PY_mb_mian},
{"6426","miao",(wchar_t*)PY_mb_miao},
{"6464","ming",(wchar_t*)PY_mb_ming},
{"6264","nang",(wchar_t*)PY_mb_nang},
{"6364","neng",(wchar_t*)PY_mb_neng},
{"6426","nian",(wchar_t*)PY_mb_nian},
{"6426","niao",(wchar_t*)PY_mb_niao},
{"6464","ning",(wchar_t*)PY_mb_ning},
{"6664","nong",(wchar_t*)PY_mb_nong},
{"6826","nuan",(wchar_t*)PY_mb_nuan},
{"7264","pang",(wchar_t*)PY_mb_pang},
{"7364","peng",(wchar_t*)PY_mb_peng},
{"7426","pian",(wchar_t*)PY_mb_pian},
{"7426","piao",(wchar_t*)PY_mb_piao},
{"7464","ping",(wchar_t*)PY_mb_ping},
{"7426","qian",(wchar_t*)PY_mb_qian},
{"7426","qiao",(wchar_t*)PY_mb_qiao},
{"7464","qing",(wchar_t*)PY_mb_qing},
{"7826","quan",(wchar_t*)PY_mb_quan},
{"7264","rang",(wchar_t*)PY_mb_rang},
{"7364","reng",(wchar_t*)PY_mb_reng},
{"7664","rong",(wchar_t*)PY_mb_rong},
{"7826","ruan",(wchar_t*)PY_mb_ruan},
{"7264","sang",(wchar_t*)PY_mb_sang},
{"7364","seng",(wchar_t*)PY_mb_seng},
{"7424","shai",(wchar_t*)PY_mb_shai},
{"7426","shan",(wchar_t*)PY_mb_shan},
{"7426","shao",(wchar_t*)PY_mb_shao},
{"7434","shei",(wchar_t*)PY_mb_shei},
{"7436","shen",(wchar_t*)PY_mb_shen},
{"7468","shou",(wchar_t*)PY_mb_shou},
{"7482","shua",(wchar_t*)PY_mb_shua},
{"7484","shui",(wchar_t*)PY_mb_shui},
{"7486","shun",(wchar_t*)PY_mb_shun},
{"7486","shuo",(wchar_t*)PY_mb_shuo},
{"7664","song",(wchar_t*)PY_mb_song},
{"7826","suan",(wchar_t*)PY_mb_suan},
{"8264","tang",(wchar_t*)PY_mb_tang},
{"8364","teng",(wchar_t*)PY_mb_teng},
{"8426","tian",(wchar_t*)PY_mb_tian},
{"8426","tiao",(wchar_t*)PY_mb_tiao},
{"8464","ting",(wchar_t*)PY_mb_ting},
{"8664","tong",(wchar_t*)PY_mb_tong},
{"8826","tuan",(wchar_t*)PY_mb_tuan},
{"9264","wang",(wchar_t*)PY_mb_wang},
{"9364","weng",(wchar_t*)PY_mb_weng},
{"9426","xian",(wchar_t*)PY_mb_xian},
{"9426","xiao",(wchar_t*)PY_mb_xiao},
{"9464","xing",(wchar_t*)PY_mb_xing},
{"9826","xuan",(wchar_t*)PY_mb_xuan},
{"9264","yang",(wchar_t*)PY_mb_yang},
{"9464","ying",(wchar_t*)PY_mb_ying},
{"9664","yong",(wchar_t*)PY_mb_yong},
{"9826","yuan",(wchar_t*)PY_mb_yuan},
{"9264","zang",(wchar_t*)PY_mb_zang},
{"9364","zeng",(wchar_t*)PY_mb_zeng},
{"9424","zhai",(wchar_t*)PY_mb_zhai},
{"9426","zhan",(wchar_t*)PY_mb_zhan},
{"9426","zhao",(wchar_t*)PY_mb_zhao},
{"9436","zhen",(wchar_t*)PY_mb_zhen},
{"9468","zhou",(wchar_t*)PY_mb_zhou},
{"9482","zhua",(wchar_t*)PY_mb_zhua},
{"9484","zhui",(wchar_t*)PY_mb_zhui},
{"9486","zhun",(wchar_t*)PY_mb_zhun},
{"9486","zhuo",(wchar_t*)PY_mb_zhuo},
{"9664","zong",(wchar_t*)PY_mb_zong},
{"9826","zuan",(wchar_t*)PY_mb_zuan},
{"24264","chang",(wchar_t*)PY_mb_chang},
{"24364","cheng",(wchar_t*)PY_mb_cheng},
{"24664","chong",(wchar_t*)PY_mb_chong},
{"24826","chuan",(wchar_t*)PY_mb_chuan},
{"48264","guang",(wchar_t*)PY_mb_guang},
{"48264","huang",(wchar_t*)PY_mb_huang},
{"54264","jiang",(wchar_t*)PY_mb_jiang},
{"54664","jiong",(wchar_t*)PY_mb_jiong},
{"58264","kuang",(wchar_t*)PY_mb_kuang},
{"54264","liang",(wchar_t*)PY_mb_liang},
{"64264","niang",(wchar_t*)PY_mb_niang},
{"74264","qiang",(wchar_t*)PY_mb_qiang},
{"74664","qiong",(wchar_t*)PY_mb_qiong},
{"74264","shang",(wchar_t*)PY_mb_shang},
{"74364","sheng",(wchar_t*)PY_mb_sheng},
{"74824","shuai",(wchar_t*)PY_mb_shuai},
{"74826","shuan",(wchar_t*)PY_mb_shuan},
{"94264","xiang",(wchar_t*)PY_mb_xiang},
{"94664","xiong",(wchar_t*)PY_mb_xiong},
{"94264","zhang",(wchar_t*)PY_mb_zhang},
{"94364","zheng",(wchar_t*)PY_mb_zheng},
{"94664","zhong",(wchar_t*)PY_mb_zhong},
{"94824","zhuai",(wchar_t*)PY_mb_zhuai},
{"94826","zhuan",(wchar_t*)PY_mb_zhuan},
{"248264","chuang",(wchar_t*)PY_mb_chuang},
{"748264","shuang",(wchar_t*)PY_mb_shuang},
{"948264","zhuang",(wchar_t*)PY_mb_zhuang},
};

#define PINYIN_TABLE_SIZE		(uint16_t)(sizeof(PinyinTable) / sizeof(PinyinTable[0]))
#define PINYIN_NUMBER_SIZE		10
#define PINYIN_PAGE_SIZE		5
#define PINYIN_MATCH_MAX		5

typedef struct
{
	uint8_t InputCount;						//输入计数
	uint8_t PageTotal;						//拼音列表页总数
	uint8_t PageIndex;						//拼音列表页索引
	uint8_t PageReamin;						//最后一页剩余的汉字个数
	uint8_t MatchCount;						//匹配的拼音计数
	uint16_t TableIndex;					//拼音列表索引
	uint16_t MatchIndex[PINYIN_MATCH_MAX];	//多个匹配的拼音
	char Number[PINYIN_NUMBER_SIZE];		//中文键盘输入的数字转化为字符串储存
}PinyinParaDef;

extern PinyinParaDef g_Pinyin;

uint16_t PinyinToChinese(char* input, uint8_t len);

void PinyinPageUpdata(uint16_t tanbel_index);

#endif

