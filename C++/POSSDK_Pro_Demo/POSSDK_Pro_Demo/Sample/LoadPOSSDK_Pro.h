#pragma once

#include "stdio.h"

#ifdef _WIN32
	#include <windows.h>

	#define POSSDK_PROCALL_MODE    __stdcall
	const char libName[32] = "POSSDK_Pro.dll";
#elif defined __linux__
	#include <dlfcn.h>
	#include <string.h>
	#define POSSDK_PROCALL_MODE
	const char libName[32] = "POSSDK_PRO.so";
#endif 

const int MAX_PATH_SIZE = 1024;

/* */
int getFullLibPath();

/* Load main*/
int Load();

/* Load all function*/
int LoadFunc();

/* Load library */
int LoadLib();

/* Free library */
int ReleaseLib();

void *Tool_LoadLib();
void *Tool_LoadFunc(char *funcName);
int Tool_LoadError(char *linuxError = NULL);
int Tool_FreeLib();

// POSSDK_PRO.h
//********************************API function************************************************


typedef int (POSSDK_PROCALL_MODE *pOpenPrinter)(char*modelName, char* portInfo);
typedef int (POSSDK_PROCALL_MODE *pClosePrinter)(int handle);
typedef int (POSSDK_PROCALL_MODE *pPrintText)(int handle, char* content, char* font);
typedef int (POSSDK_PROCALL_MODE *pQueryStatus)(int handle, char* status);
typedef int (POSSDK_PROCALL_MODE *pPaperCut)(int handle, int cutMode, int distance);
typedef int (POSSDK_PROCALL_MODE *pFeedLines)(int handle, int line);
typedef int (POSSDK_PROCALL_MODE *pEnumDevice)(int portType, char* deviceInfo, int deviceInfoLen);
typedef int (POSSDK_PROCALL_MODE *pBarcodePrint)(int devHandle, int type, char* data, int dataLen, char *format);
typedef int (POSSDK_PROCALL_MODE *pPrintImageFile)(int devHandle, char *Image, char *format);
typedef int (POSSDK_PROCALL_MODE  *pPrintDownloadedImage)(int devHandle, int Type, int ImageID, char *format);
typedef int (POSSDK_PROCALL_MODE *pDownloadImage)(int devHandle, int Type, char *ImageList, char *format);
typedef int (POSSDK_PROCALL_MODE *pPrintContent)(int devHandle, int Type, char *content);

//����ֵ
const int SUCCESS = 0;										//�ɹ�

//ͨѶ����
const int COMMU_ERR_OPEN_PORT = -1;							//�򿪶˿�ʧ��
const int COMMU_ERR_WRITE_PORT = -2;						//д����ʧ��
const int COMMU_ERR_READ_PORT = -3;							//������ʧ��
const int COMMU_ERR_TIME_OUT = -4;							//��д��ʱ
const int COMMU_ERR_CLOSE_PORT = -5;						//�رն˿�ʧ��
const int COMMU_ERR_PORT_NOT_SUPPORT = -6;					//��֧�ֵĶ˿�
const int COMMU_ERR_PORT_REATCH_MAXNUM = -7;				//�˿ڴ������ﵽ����
const int COMMU_ERR_NO_ONE_DEVICE = -8;						//�豸������Ψһ

//��������
const int PARA_ERR_TEXT_X = -17;								//�ı��������������
const int PARA_ERR_TEXT_Y = -18;								//�ı��������������
const int PARA_ERR_TEXT_LINESPACE = -19;				//�ı������м�����
const int PARA_ERR_FORMAT = -20;							//������ʽ��
const int PARA_ERR_ITEM_ILLEGAL = -21;						//����ֵ���Ϸ�
const int PARA_ERR_FILE_NOT_EXIST = -22;					//�ļ������ڻ���ļ�ʧ��
const int PARA_ERR_TEXT_BOLD = -23;							//�ı���ʽ�������Ӵ֣���
const int PARA_ERR_TEXT_ALIGNMENT = -24;					//�ı���ʽ���������룩��
const int PARA_ERR_TEXT_HORMAGNIFY = -25;					//�ı���ʽ����������Ŵ󣩴�
const int PARA_ERR_TEXT_VERMAGNIFY = -26;					//�ı���ʽ����������Ŵ󣩴�
const int PARA_ERR_TEXT_UNDERLINE = -27;					//�ı���ʽ�������»��ߣ���
const int PARA_ERR_TEXT_ITALICS = -28;						//�ı���ʽ��������б����
const int PARA_ERR_TEXT_FONT = -29;							//�ı���ʽ���������壩��
const int PARA_ERR_BAR_TYPE = -30;							//�������ʹ�
const int PARA_ERR_BAR_DATA = -31;							//�������ݴ�
const int PARA_ERR_BAR_DATALEN = -32;						//�������ݳ��ȴ�
const int PARA_ERR_BAR_BASICWIDTH = -33;					//�����ʽ����������Ԫ�ؿ�ȣ���
const int PARA_ERR_BAR_HEIGHT = -34;						//�����ʽ����������߶ȣ���
const int PARA_ERR_BAR_HRIPOS = -35;						//�����ʽ�����������ַ�λ�ã���
const int PARA_ERR_BAR_HRIFONT = -36;						//�����ʽ�����������ַ����ͣ���
const int PARA_ERR_BAR_X = -37;								//�����ʽ������ˮƽ��������߽�ľ��룩��
const int PARA_ERR_BAR_Y = -38;								//�����ʽ��������ֱ�������ʼ��λ�����ϱ߽���룩��
const int PARA_ERR_BAR_ERRORCORRECT = -39;					//�����ʽ����������ȼ�����
const int PARA_ERR_BAR_ROWS = -40;							//�����ʽ�������������������
const int PARA_ERR_BAR_COLS = -41;							//�����ʽ�������������������
const int PARA_ERR_BAR_SCALEH = -42;						//�����ʽ������������۱ȸ߶ȣ���
const int PARA_ERR_BAR_SCALEV = -43;						//�����ʽ������������۱ȿ�ȣ���
const int PARA_ERR_BAR_SYMBOLTYPE = -44;					//�����ʽ����������������ͣ���
const int PARA_ERR_BAR_LANGUAGEMODE = -45;					//�����ʽ����������ģʽ����
const int PARA_ERR_BAR_GS1TYPE = -46;						//�����ʽ������GS1�������ͼ��ַ�������
const int PARA_ERR_BAR_BASICHEIGHT = -47;					//�����ʽ������GS1����Ԫ�ظ߶ȣ���
const int PARA_ERR_BAR_SEGMENTNUM = -48;					//�����ʽ������GS1ÿ��������Ŷ�������
const int PARA_ERR_BAR_SEPHEIGHT = -49;						//�����ʽ������GS1�ָ����߶ȵ�������
const int PARA_ERR_BAR_HRITYPE = -50;						//�����ʽ������GS1ע���ַ����ͣ���
const int PARA_ERR_BAR_AI = -51;							//�����ʽ������GS1Ӧ�ñ�ʶ������
const int PARA_ERR_ARRAY_TOO_SMALL = -52;					//��������̫С
const int PARA_ERR_PROPERTY_NAME = -53;						//��ʽ���в�������������
const int PARA_ERR_BMP_TYPE = -60;							//λͼ�ӿ����Ͳ�����
const int PARA_ERR_BMP_IMAGE = -61;							//λͼ�ӿ�·�������ݴ�
const int PARA_ERR_BMP_ID = -62;							//λͼ�ӿ�ID������
const int PARA_ERR_BMP_X = -63;								//λͼ��ʽ����X���꣩��
const int PARA_ERR_BMP_Y = -64;								//λͼ��ʽ����Y���꣩��
const int PARA_ERR_BMP_WIDTH = -65;							//λͼ��ʽ�������ſ�ȣ���
const int PARA_ERR_BMP_HEIGHT = -66;						//λͼ��ʽ�������Ÿ߶ȣ���
const int PARA_ERR_BMP_SCALE = -67;							//λͼ��ʽ�������ű�������
const int PARA_ERR_BMP_ZOOMPARAM = -68;						//λͼ��ʽ��������ϵ������
const int PARA_ERR_BMP_DITHER = -69;						//λͼ��ʽ������ֵ���㷨����
const int PARA_ERR_BMP_THRESHOLD = -70;						//λͼ��ʽ������ֵ�̶���ֵ����ֵ����
const int PARA_ERR_BMP_FILEFORMAT = -71;					//ͼƬ��ʽ��
const int PARA_ERR_BMP_TOOBIG = -72;					//ͼƬ����

//ͨ�ô���
const int ERR_LOAD_RESOURCE_FAIL = -80;						//���������Ķ�̬�����Դ�ļ�ʧ��
const int ERR_FUNC_NOT_SUPPORT = -81;						//�ù��ܲ�֧��
const int ERR_INVALID_HANDLE = -82;							//��Ч���
const int ERR_RELEASE_SOURCE = -83;							//�ͷ���Դ����
const int ERR_PORT_ENUM_DEVICE_FAILED = -84;				//δ�ҵ��豸
const int ERR_UNSUPPORT_DEVICE = -85;						//��֧�ֵĻ���
const int ERR_INNER_FAILED = -86;							//�ڲ�ִ��ʧ��
const int ERR_MALLOC_FAILED = -87;							//�ڴ�����ʧ��

//ͨѶ��������
const int COMMU_PARA_ERR_PORT_COM_BAUDRATE =  -100;			//�˿���Ϣ���ڲ�������Ч
const int COMMU_PARA_ERR_PORT_COM_HANDSHAKE = -101;			//�˿���Ϣ���������ź���Ч

//λͼ�������
const int ERR_IMG_CONVERSION_BMP = -140;					//ͼƬ��ʽת����BMP��ʽ��أ���
const int ERR_IMG_CONVERSION_JPEG = -141;					//ͼƬ��ʽת����JPEG��ʽ��أ���
const int ERR_IMG_CONVERSION_PNG = -142;					//ͼƬ��ʽת����PNG��ʽ��أ���
const int ERR_IMG_CONVERSION_GIF = -143;					//ͼƬ��ʽת����GIF��ʽ��أ���
const int ERR_IMG_CONVERSION_TIFF = -144;					//ͼƬ��ʽת����TIFF��ʽ��أ���
const int ERR_IMG_DITHER = -145;							//ͼ���ֵ�������㷨��
const int ERR_IMG_ZOOM = -146;								//ͼ�����Ŵ�

//XML����
const int ERR_XML_FORMAT = -161; // ������XML��׼
const int ERR_XML_PARAMETER = -162; // �����ϱ�ǩҵ���߼�
const int ERR_XML_UNKNOWNTAG = -163; //δ֪�ı�ǩ
const int ERR_XML_UNKNOWNATTRIBUTE = -164;  //δ֪������

//ҳģʽ����
const int PARA_ERR_PAGE_X = -181; // ҳģʽ��������X��
const int PARA_ERR_PAGE_Y = -182; // ҳģʽ��������
const int PARA_ERR_PAGE_WIDTH = -183; //ҳģʽ��������
const int PARA_ERR_PAGE_HEIGHT = -184; //ҳģʽ�������� 

//�������� Barcode type
enum BarCodeSymbology {						// �������ͺ� Barcode type No
	BarCode_UPCA = 1,
	BarCode_UPCE = 2,
	BarCode_EAN13 = 3,
	BarCode_EAN8 = 4,
	BarCode_Code39 = 5,
	BarCode_ITF = 6,
	BarCode_Codebar = 7,
	BarCode_Code93 = 8,
	BarCode_Code128 = 9,
	BarCode_QR = 10,
	BarCode_PDF417 = 11,
	BarCode_MAXICODE = 12,
	BarCode_GS1 = 13
};

//ͼƬ���� Image type
const int IMAGE_TYPE_RAM = 0;
const int IMAGE_TYPE_FLASH = 1;



//*****************API function************************************************
//ͨѶ Communication

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief ö���豸
///
/// @param [in]    portType    �˿����͡�
/// @param [out]   deviceInfo   �豸��Ϣ��ÿ���豸���ƽ�����Ϊ@���˽���������Ϊö�ٵ��豸������Ϣ��ֻ���ڻ��ֶ���豸��
///                    ��deviceInfo�����ǡ�USBAPI|192@USBCLASS|BTP-U80(U)1@������192.168.1.251@ 192.168.1.249@�����û���ͨ����@���ַ����в��           
/// @param [in]    deviceInfoLen    �豸��Ϣ���ȣ�����deviceInfo��Сһ�¡�
/// @return
/// �ɹ�����0����ʾö�ٵ����豸������������deviceInfo����ֵ�ǡ�USBAPI|192@USBCLASS|BTP-U80@��Ϊ����
///      ��Ϊ�����С�USBAPI|192���͡�USBCLASS|BTP-U80�������豸���򷵻�ֵΪ2
/// ʧ�ܣ�������
///
/// @~English
/// @brief Enumerate devices
///
/// @param [in]    portType    Port Type��
/// @param [out]   deviceInfo  The buffer of name list each name terminator with @, this terminator is not used as 
///					the name information for the enumeration. It is only used to divide multiple name devices. Such 
///					as "deviceInfo" maybe "USBAPI | 192@USBCLASS|BTP - U80(U)1@"��"192.168.1.251@ 192.168.1.249@"��
///					Users can split it by character"@" .
/// @param [in]    deviceInfoLen    The length of the device information must be the same as the size of the deviceInfo.
/// @return
/// Success:��0,indicates the number of devices enumerated,Take the above deviceInfo return value as
///			"USBAPI|192@USBCLASS|BTP-U80@"as an example,Because there are two devices"USBAPI|192" and "USBCLASS|BTP-U80", 
///			the return value is 2.
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE EnumDevice(int portType, char* deviceInfo, int deviceInfoLen);

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief �򿪶˿�
///
/// @param [in]   modelName    ��ӡ���ͺ����ƣ����硰BTP-R880NP����
/// @param [in]   portInfo     �˿���Ϣ����  "COM1|19200"��"USB"��"USBAPI|912"��
///                            "USBCLASS | BTP - S80(U)1"��"192.168.1.251"
/// @return
/// �ɹ�����0���豸���
/// ʧ�ܣ�������
///
/// @~English
/// @brief Open Printer
///
/// @param [in]   modelName    Printer model name, for example "BTP-N80".
/// @param [in]   portInfo     port information,such as  "COM1|19200","USB","USBAPI|912" or
///                            "USBCLASS | BTP - S80(U)1" or "192.168.1.251"
/// @return
/// Success: �� 0 device handle
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE OpenPrinter(char*modelName, char* portInfo);

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief �رն˿�
///
/// @param [in]    devHandle   �豸�������OpenPrinter����Ч����ֵ����ֻ��һ̨�豸ʱ���Դ�0��
///                            
/// @return
/// �ɹ���0
/// ʧ�ܣ�������
///
/// @~English
/// @brief Close Printer
///
/// @param [in]   devHandle   Device handle. The effective return value of OpenPrinter. 
///							  When there is only one device, it can be 0.
///                            
/// @return
/// Success: 0
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE ClosePrinter(int devHandle);

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief �ı���ӡ
///
/// @param [in]   devHandle   �豸�������OpenPrinter����Ч����ֵ����ֻ��һ̨�豸ʱ���Դ�0��
/// @param [in]   content     ��ӡ����
/// @param [in]   font     �ò���Ϊ��ϣ��硰Font=FontA|Bold=1| Italics =1|Underline=1����
///                    Ҳ����ΪNULL����ַ�������δ���ù�������Font����Ĭ��ΪFontA������Ĭ��Ϊ���Ӵ֡�
///                    ����롢����Ŵ����»��ߡ���б�塣����������ΪFontA����FontBʱ��HScale��VScale��
///                    ȡֵ��ΧΪ1-6���������ȡֵ��ΧΪ15-170����֮ǰ�����ù��������������ϴ����á�
///             �ֶκ���	   �ֶ�����	    ����ֵ
///              �Ӵ�		Bold	    1 / 0���Ӵ� / ���Ӵ֣�
///				 ����		Align		0 / 1 / 2������� / ���� / �Ҷ��룩
///				 ����Ŵ�	HScale		1 - 6��TTFΪ15 - 170��
///				 ����Ŵ�	VScale		1 - 6��TTFΪ15 - 170��
///				 �»���		Underline	1 / 0���»��� / �ޣ�
///				 ��б		Italics		1 / 0��б�� / �ޣ�
///				 ����		Font		����²��ڲ�����
///
///							�ڲ�����		��ע
///							FontA		12 * 24�ڲ����� / �����������Եı�׼�����֣�
///							FontB		9 * 17�ڲ�����
///							����			TrueType����
///							��������		TrueType����
///							��			����TrueType����
///	˵��
///		1.	TrueType���岻֧�ֵ��ж���������
///		2.	TrueType����HScale��VScale���ڵ���15��С��170, Ϊ�ֺţ��Ƽ�ʹ�ñ���1:2�����硰HScale = 15 | VScale = 30����
///		3.	TrueType���岻֧�ֶ��롢б�塢�»��ߡ�
///		4.	����PrintText�ӿڣ����ݽ���ʱ�����\n���з�, ���ߵ���FeedLines�ӿڲŻ��ӡ��
/// @return
/// �ɹ���0
/// ʧ�ܣ�������
///
/// @~English
/// @brief Text Print
///
/// @param [in]   devHandle   Device handle. The effective return value of OpenPrinter. 
///							  When there is only one device, it can be 0.
/// @param [in]   content     print contents
/// @param [in]   font     This parameter is a combination, such as ��Font=FontA|Bold=1| 
///						   Italics =1|Underline=1��, It can also be null or empty string. 
///						   If font style has not been set, font is fontA by default, and 
///						   others are non bold, left aligned, horizontal enlarged, non underlined 
///						   and non italicized by default. When the font is set to FontA or FontB, 
///						   the value range of HScale and VScale is 1-6, and the value range of other 
///						   cases is 15-170.
///						   If the font style has been set before, the last setting will continue.
///
///						   Field meaning	Field name	Attribute value
///						   Bold				Bold		1 / 0(Bold / unbold)
///						   alignment		Align		0 / 1 / 2(Align left / Center / Align right)
///						   Horizontal 		HScale		1 - 6(TTF is 15 - 170)
///						   Vertical 		VScale		1 - 6(TTF is 15 - 170)
///						   Underline		Underline	1 / 0(Underline / none)
///						   Italics			Italics		1 / 0(Italics / none)
///						   Font				Font		See the internal fonts in the table below for details
///							
///							Internal font	Remarks
///							FontA			12 * 24 Internal font / (Or standard Song font in other languages)
///							FontB			9 * 17 Internal font
///							Regular			script	TrueType fonts
///							stsong			TrueType  fonts
///							��				Other TrueType fonts
/// @return
/// Success: 0
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE PrintText(int devHandle, char* content, char* font);

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief ״̬��ѯ
///
/// @param [in]    devHandle	�豸�������OpenPrinter����Ч����ֵ����ֻ��һ̨�豸ʱ���Դ�0��
/// @param [out]   status		״̬Ϊ�ַ������ӣ����磺��PaperOut|CoverOpen��
///					�ַ���			����			ֵ
///					Normal			����			1
///					PaperOut		ȱֽ			2
///					PaperNearEnd	ֽ����		4
///					CoverOpen		�ϸ�̧��		8
///					HeadOverheated	��ӡͷ����	16
///					CutterError		�е���		32
///	˵��
///		1.	��Ҫ����status���鳤�ȡ�512
///		2.	֧�ַ���ֵ����״̬�����ϱ���ֵ��
///
/// @return
/// �ɹ����ɹ�����0��״̬�룬�ɰ�λ����״̬������status����ֵ���屣��һ��
/// ʧ�ܣ�������
///
/// @~English
/// @brief Query Status
///
/// @param [in]    devHandle	Device handle, which is the effective return value of openprinter, 
///								can be passed to 0 when there is only one device.
/// @param [out]   status		The status is character string overlay, for example:��PaperOut|CoverOpen��
///					
///								Character		string		Meaning	Value
///								Normal			Normal				1
///								PaperOut		Paper Out			2
///								PaperNearEnd	Paper Near End		4
///								CoverOpen		Cover Open			8
///								HeadOverheated	Head Over heated	16
///								CutterError		Cutter Error		32
///	Description
///		1.	The length of the passed in status array should be greater than or equal to 512
///		2.	Support return value parsing status, as shown in the table above.
///
/// @return
/// Success: Status code �� 0, The status can be parsed bit by bit, and the meaning is consistent 
///			 with the status return value
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE QueryStatus(int devHandle, char* status);

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief ��ֽ
///
/// @param [in]   devHandle		�豸�������OpenPrinter����Ч����ֵ����ֻ��һ̨�豸ʱ���Դ�0��
/// @param [in]   cutMode		ȫ�� 1������ 0
/// @param [in]   distance		��ֽǰ��ֽ����,ȡֵ��Χ��0~255������λ����
///
///	˵��
///		1.	��ֽ������������йأ����ֻ��ͽ�֧�ְ��л���ȫ��
///		2.	�ýӿ�ȷ����ֽʱ������ӡ�����ͳ��е�֮����ֽ�������ڴ�ӡ�����ϡ�
///		3.	���ڸ���ӡ����ӡͷ���е�֮����벻ͬ����ֽģ��ṹ��ͬ��ԭ��distance����ʵ����Чֵ��Χ��Ϊ0 - 255��
///			��Ҫ����ʵ��������е�����
/// @return
/// �ɹ���0
/// ʧ�ܣ�������
///
/// @~Chinese
/// @brief Cut Paper
///
/// @param [in]   devHandle		Device handle, which is the effective return value of openprinter, 
///								can be passed to 0 when there is only one device.
/// @param [in]   cutMode		Full cut 1, half cut 0
/// @param [in]   distance		Distance before paper cutting, value range (0 ~ 255), unit: point
///
///	Description
///		1.	The paper cutting situation is related to the specific model, some models only 
///			support half cutting or full cutting
///		2.	The interface ensures that the paper will not be cut on the printed content 
///			after the printed content is sent out of the cutter.
///		3.	Due to the different distance between the printer head and the cutter and 
///			the different structure of the paper output module, the actual effective value range 
///			of the distance parameter is not 0-255, which needs to be adjusted according to the 
///			actual situation.
/// @return
/// Success: 0
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE PaperCut(int devHandle, int cutMode, int distance);

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief ��ֽ
///
/// @param [in]   devHandle		�豸�������OpenPrinter����Ч����ֵ����ֻ��һ̨�豸ʱ���Դ�0��
/// @param [in]   line			��ֽ������ȡֵ��Χ��0~255����λ����
///
///	˵����
///		��ӡ��ӡ�������������ݲ���ֽline�С�
/// @return
/// �ɹ���0
/// ʧ�ܣ�������
///
/// @~English
/// @brief Feed Paper
///
/// @param [in]   devHandle		Device handle, which is the effective return value of openprinter, 
///								can be passed to 0 when there is only one device.
/// @param [in]   line			Number of feed lines, value range (0 ~ 255) unit: Lines
///
///	Description:
///		Print the data in the printer buffer and feed the paper line
/// @return
/// Success: 0
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE FeedLines(int devHandle, int line);

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief �����ӡ
///
/// @param [in]   devHandle		�豸�������OpenPrinter����Ч����ֵ����ֻ��һ̨�豸ʱ���Դ�0��
/// @param [in]   type			��������,���£�
///								��Чֵ	��������
///								1		UPC - A
///								2		UPC - E
///								3		JAN13(EAN13)
///								4		JAN8(EAN8)
///								5		CODE39
///								6		ITF
///								7		CODEBAR
///								8		CODE93
///								9		CODE128
///								10		QRCODE
///								11		PDF417
///								12		MAXICODE
///								13		GS1
///
/// @param [in]   data		��������
/// @param [in]   dataLen	�������ݳ���
/// @param [in]    format�������ʽ���硰BasicWidth=1|Height=50|HriPos=0��,��Сд���ޣ��Է��š�|���ָ���
///					ע����format����NULL���߿��ַ���������Ĭ��ִֵ�С�
///	format������������£�
/// {
///		BasicWidth: �������Ԫ�ؿ�ȣ�
///					һά�룺��Ч��Χ1 - 6��Ĭ����2
///					��ά�룺��Ч��ΧQR 1 - 10��Ĭ��5��PDF417 1 - 7, Ĭ��2
///     Height: һά�룺����߶ȣ���λ���㣩����Ч��Χ1-255��Ĭ����50,GS1�߶ȣ���Ч��Χ2 - 250��Ĭ����50		
///				��ά�룺����Ԫ�ظ߶ȣ���λ���㣩����Ч��Χ2 - 25��Ĭ��10
///     HriPos�������ַ�λ�ã���һά������Ч��Ĭ����2
///					��Чֵ		λ��
///					0			����ӡ
///					1			ֻ�������Ϸ���ӡ
///					2			ֻ�������·���ӡ
///					3			�����ϡ��·�����ӡ
///		HriFont�������ַ��������ͣ���һά������Ч��Ĭ����0
///					��Чֵ		λ��
///					0			��׼ASCII
///					1			ѹ��ASCII
///		X��ˮƽ��������߽�ľ��루��λ���㣩��Ĭ�� - 1
///					��Чֵ		���뷽ʽ
///					- 1			����
///					- 2			����
///					- 3			����
///					��0			����߽���루�㣩
/// ���¼������QR�������ã�
///		LanguageMode : ����ģʽ 0������ 1�����ģ�Ĭ��Ϊ0
///		ErrorCorrect������ȼ�, ��Ч��ΧQRCode : 0 - 3 : 0����L����, 1����M����, 2����Q���� 3����H����Ĭ��ΪL����
///	���¼����PDF417�����ã�
///		Rows���������������Ч��Χ3 - 90��Ĭ����5
///		Cols : �������������Ч��Χ1 - 30��Ĭ����5
///		ScaleH��������۱ȸ߶ȣ���Ч��Χ1 - 10��Ĭ����2
///		ScaleV��������۱ȿ�ȣ���Ч��Χ1 - 100��Ĭ����10
///		ErrorCorrect������ȼ�, �ȼ�Խ����������Խ��, ��Ч��ΧPDF417 : 0 - 8��Ĭ��Ϊ3
///	���¼����GS1�����ã�
///		GS1�����Ƕ���������߸������룬ͨ�������������Ƿ�������ݷָ����� | �����֣����ڡ� | ��Ϊ�����룬�����Ƕ�����
///	DataBar���롣�� | ��֮ǰ���Ǹ������е�DataBar�������ݣ��� | ��֮����Ǹ�������2D��������ݡ�
///		GS1Type:  GS1�������ͼ��ַ�������Ч��Χ1-7��Ĭ��Ϊ1,��������ĵ�
///		BasicHeight: ��������2D������Ż���Ԫ�ظ߶ȵ�������Ч��Χ1-10�㣬Ĭ����3
///		SegmentNum��ÿ��������Ŷ�����ֻ��������������չ������ʱ��Ҫ���ô˲�������Ч��Χ4 - 20��Ĭ����6
///		SepHeight���ָ����߶ȵ���������������DataBar��������߶�����DataBar�����͡�ȫ������͡���չ��������Ҫ���ô˲�������Ч��Χ1 - 10�㣬Ĭ����1
/// 	HriType��ע���ַ����ݣ���Ч��Χ1 - 4��Ĭ����1,��������ĵ�
///		AI���Ƿ�Ӧ��AI��Ӧ�ñ�ʶ������0��ʾ��Ӧ��AI��1��ʾӦ��AI��Ĭ����0
/// }
/// @return
/// �ɹ���0
/// ʧ�ܣ�������
///
/// @~English
/// @brief Barcode Printing
///
/// @param [in]   devHandle		Device handle, which is the effective return value of openprinter, 
///								can be passed to 0 when there is only one device.
/// @param [in]   type			Barcode Type,as below:
///							Valid Value	Barcode Type
///								1		UPC - A
///								2		UPC - E
///								3		JAN13(EAN13)
///								4		JAN8(EAN8)
///								5		CODE39
///								6		ITF
///								7		CODEBAR
///								8		CODE93
///								9		CODE128
///								10		QRCODE
///								11		PDF417
///								12		MAXICODE
///								13		GS1
///
/// @param [in]   data		Barcode data
/// @param [in]   dataLen	Barcode data length
/// @param [in]   format    Bar code format, Such as "BasicWidth=1|Height=50|HriPos=0", the case 
//							is not limited, separated by the symbol ��|��.
///	The specific attributes of format are as follows:
/// {
///		BasicWidth: The width of the basic element of the barcode,
///					One dimensional code: valid range 1-6, default is 2
///					QR Code: effective range QR 1-10, default 5; PDF417 1-7, default 2
///     Height: One dimensional code: bar code height (unit: point), valid range 1-255, default is 50
///				GS1 height, valid range 2-250, default is 50
///				QR Code: bar code element height (unit: point), valid range 2-25, default is 10
///     HriPos��Barcode character position, only one-dimensional barcode is valid, the default is 2
///					Value		Position
///					0			No printing
///					1			Print only above the barcode
///					2			Print only below the barcode
///					3			Print both above and below the barcode
///		HriFont��Barcode character font type, only one-dimensional barcode is valid, the default is 0
///					Value		Position
///					0			Standard ASCII
///					1			Compression ASCII
///		X��The horizontal distance from the left boundary (unit: point), default -1
///					Value		Alignment
///					- 1			Left-aligning 
///					- 2			Right-aligning
///					- 3			Center-aligning 
///					��0			Distance from left boundary (point)
/// The following items only work on QR Code:
///		LanguageMode:Language mode 0: Chinese character 1: Japanese, default is 0
///		ErrorCorrect:Error correction level, effective range, QRCode:0-3 : 0 for level L, 
///					 1 for level M, 2 for level Q, and 3 for level H. The default is L level
/// The following only work on PDF417:
///		Rows: The number of lines of barcode, valid range 3-90, default is 5
///		Cols: The number of bar code columns, the effective range is 1-30, the default is 5
///		ScaleH: Bar code appearance ratio height, valid range 1 - 10, default is 2
///		ScaleV: Bar code appearance ratio width, valid range 1-100, default is 10
///		ErrorCorrect: Error correction level: the higher the level is, the larger the barcode capacity is. 
///					  The effective range is PDF417:0-8, which is 3 by default
///	The following only work on GS1:
///		GS1Type: GS1 barcode type and character, valid range 1-7, default to 1
///		BasicHeight: The height points of basic elements of 2D barcode symbol in compound code, 
///					 the effective range is 1-10 points, the default is 3
///		SegmentNum: The number of segments of bar code symbol in each line. This parameter needs to be set 
///					only when the bar code type is extended layer type. The valid range is 4-20, and the default is 6
///		SepHeight: Separator height points, bar code type is DataBar composite code or independent DataBar 
///				   layer type, omni-directional layer type, extended layer type, you need to set this parameter. 
///				   The valid range is 1-10 points. The default value is 1
/// 	HriType: Comment character content, valid range 1-4, default is 1
///		AI:Whether to apply AI (application identifier): 0 means not to apply AI; 1 means to apply AI, the default is 0
/// }
/// @return
/// Success: 0
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE BarCodePrint(int devHandle, int type, char* data, int dataLen, char *format);

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief ͼƬ��ӡ
///
/// @param [in]   devHandle		�豸�������OpenPrinter����Ч����ֵ����ֻ��һ̨�豸ʱ���Դ�0��
/// @param [in]   Image			ͼƬ�ļ�·����
/// @param [in]   format		ͼƬ�����ʽ���硰x=0|y=0|Width=0|Height=0|Scale=50|Zoom=1|Dither=0|Threshold=-1��,��Сд���ޣ��Է��š�|���ָ���
///					ע����format����NULL���߿��ַ���������Ĭ��ִֵ�С�
///	format������������£�
/// {
///		x: λͼ��ӡ�����꣬Ĭ��0����Чֵ��ΧΪ-3-255����λΪ�㡣-1��������룻-2�����ж��룻-3�����Ҷ��롣
///		y: λͼ��ӡ�����꣬��ҳģʽ����Ч��Ĭ��0����Чֵ��ΧΪ0-255����λΪ�㡣
///        Width��Height��ͼ��������ĳ����������������ޣ�����Ϊ0��Ĭ��Ϊ0��
///                                   ȡֵ0ʱ��ͼ��ԭ������д�ӡ��
///                                   ����ֵ��������ʱ����Ĭ��ֵ0���д���
///                                   ������һ��ʱ����ԭͼ������ֵ�ı������з�����
///        Scale�� ������������λΪ%�������ޣ�����Ϊ0��Ĭ��Ϊ100��
///                   ȡֵ0ʱ����100��������ԭͼ��ӡ��
///                   ���ȼ�����width��height��������width��height����ʱ���˲�������Ч��
///	    Zoom�������㷨������Ĭ��ֵ3��
///                    ȡֵ1��������ֵ����
///                    ȡֵ2��˫���Բ�ֵ����
///                 	ȡֵ3���ٽ���ֵ����
///        Dither����ֵ�����㷨��ʽ��Ĭ��0��
///                      0���̶���ֵ����
///                      1��BayerM3
///                      2��BayerM4
///                      3�������ɢ��
///         Threshold����ֵ�����㷨�̶���ֵ����ֵ��������ditherȡֵ0ʱ��Ч��Ĭ��-1��������Χ-1-255������-1ʱʹ���Զ���ֵ
///
/// }
/// @return
/// �ɹ���0
/// ʧ�ܣ�������
///
/// @~English
/// @brief Print Image file
///
/// @param [in]   devHandle		Device handle, which is the effective return value of openprinter, 
///								can be passed to 0 when there is only one device.
/// @param [in]   Image			Image file path, can be relative or absolute path.
///
/// @param [in]   format		This parameter is the format string of the image processing  mode, 
///								such as "x=0|y=0|Width=0|Height=0|Scale=50|Zoom=1|Dither=0|Threshold=-1".
///								It can also be an empty string. When it is an empty string, the default value is used.
///								
/// The meaning of each parameter, the value range and the default value are as follows.
/// {
///		x:	The horizontal offset, the value range is -3 to 255, and the unit is point. The default value is 0.
///			Among them, -1 means left-aligned, -2 means center-aligned, and -3   means right-aligned. 
///			This alignment is only valid in row mode.
///		y:	Vertical offset, the value range is 0 to 255, and the unit is point.  The default value is 0. 
///			This parameter is only valid in page mode.
///     Width��Height:	The final print length and width of the image,the      minimum value is 0, no upper limit, 
///						and the unit is pixel. The default value is 0. 
///                     When the value is 0, it is processed according to the actual length and width of the picture. 
///                     When only one of the two parameters is set, the scaling process is performed according to the
///						ratio of the set value to the actual value of  the picture.
///     Scale:	Image zoom ratio, the minimum value is 0, no upper limit, the unit is %. The default value is 0. 
///             When the value is 0, it is processed as 100 and the original image is  printed. 
///             The priority is lower than Width and Height. When a value in Width and Height is set, 
///				this setting will not take effect.
///	    Zoom:	Image zooming mode, the value ranges from 1 to 3, and the    default value is 3. 
///                   Value 1: Cubic interpolation method;
///                   Value 2: Bilinear interpolation method; 
///                   Value 3: Proximity interpolation method.
///        Dither:	Binary dithering algorithm, the value ranges from 0 to 3, and the default value is 0. 
///                      Value 0: fixed threshold method; 
///                      Value 1: BayerM3; 
///                      Value 2: BayerM4; 
///                      Value 3: Error diffusion method.
///         Threshold:	The threshold parameter of the fixed threshold method, the  value range is -1 to 255, and the default value is -1. 
///						It takes effect only when Dither is set to 0. 
///						The value - 1 is to use the automatic threshold.��
/// }
/// @return
/// Success: 0
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE PrintImageFile(int devHandle, char *Image, char *format);

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief ������ͼƬ��ӡ
///
/// @param [in]   devHandle	�豸�������OpenPrinter����Ч����ֵ����ֻ��һ̨�豸ʱ���Դ�0��
/// @param [in]   Type		ͼƬ���ط�ʽ��
///                                       0-RAMλͼ
///                                       1-Flashλͼ
/// @param [in]   ImageID	ͼƬ������š�
///                                       RAMλͼȡֵ��Χ1-8
///                                       Flashλͼȡֵ��Χ1-255
/// @param [in]   format�������ʽ���硰x=0|y=0��,��Сд���ޣ��Է��š�|���ָ���
///					ע����format����NULL���߿��ַ���������Ĭ��ִֵ�С�
///		x: λͼ��ӡ�����꣬Ĭ��0����Чֵ��ΧΪ-3-255����λΪ�㡣-1��������룻-2�����ж��룻-3�����Ҷ��롣
///		y: λͼ��ӡ�����꣬��ҳģʽ����Ч��Ĭ��0����Чֵ��ΧΪ0-255����λΪ�㡣
/// }
/// @return
/// �ɹ���0
/// ʧ�ܣ�������
///
/// @~English
/// @brief Print the downloaded image
///
/// @param [in]   devHandle		Device handle, which is the effective return value of openprinter, 
///								can be passed to 0 when there is only one device.
///
/// @param [in]   Type		Image download method. 0-RAM,1-Flash
///
/// @param [in]   ImageID	The serial number of the picture when downloading, 
///							the value range of RAM is 1-8, and the value range of Flash is 1-255.
///
/// @param [in]   format	The image has been processed when downloading. Only the print coordinates 
///							are set here, such as "x=-1|y=0". It can also be an empty string, 
///							and the default is an empty string. Value, the meaning of each parameter, 
///							value range and default value are as follows.
///		x:	The horizontal offset, the value range is -3 to 255, and the unit is point. The default value is 0. 
///			Among them, -1 means left - aligned, -2 means center - aligned, and -3 means  right - aligned.
///			This alignment is only valid in row mode.
///		y:	Vertical offset, the value range is 0 to 255, and the unit is point. The default value is 0. 
///			This parameter is only valid in page mode.
/// }
/// @return
/// Success: 0
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE  PrintDownloadedImage(int devHandle, int Type, int ImageID, char *format);

//////////////////////////////////////////////////////////////////////////
///
/// @~Chinese
/// @brief ����ͼƬ
///
/// @param [in]   devHandle		�豸�������OpenPrinter����Ч����ֵ����ֻ��һ̨�豸ʱ���Դ�0��
/// @param [in]   Type		ͼƬ���ط�ʽ��
///                                       0-RAMλͼ
///                                       1-Flashλͼ
/// @param [in]   ImageList 	����ͼƬ·���б���֧��·������������Ҫ��һ��·��ֵ
///                                       �ԡ�|���ָ������磺��./aaa.jpg|C:\\S.PNG����
///                                       Flashλͼȡֵ��Χ1-255
///  @param [in]	format����������μ�PrintImageFile�ӿڵ�format�����������˽ӿ�����x, y�������һ��ImageList������ͼƬ������ͳһ����
///
/// }
/// @return
/// �ɹ���0
/// ʧ�ܣ�������
///
/// @~English
/// @brief Download images to printer
///
/// @param [in]   devHandle		Device handle, which is the effective return value of openprinter, 
///								can be passed to 0 when there is only one device.
/// @param [in]   Type			Image download method. 0-RAM,1-Flash
///
/// @param [in]   ImageList 	The list of download image file paths can be relative or absolute paths. 
///								At least one path value is required, and the paths are directly separated by "|". 
///								For example: "./image/RAM1.bmp|./image/RAM2.bmp|./image/RAM3.bmp".
///
///  @param [in]  format		The specific parameters are described in the format parameter description of
///								the printimagefile interface, which is no x, y, and all the images in the 
///								imagelist are processed uniformly.
/// }
/// @return
/// Success: 0
/// Failure: error code
///
//////////////////////////////////////////////////////////////////////////
int POSSDK_PROCALL_MODE DownloadImage(int devHandle, int Type, char *ImageList, char *format);

int POSSDK_PROCALL_MODE PrintContent(int devHandle, int Type, char *content);


