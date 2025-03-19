//
// MyPage.xaml.cpp
// MyPage 클래스의 구현
//

#include "pch.h"
#include "MyPage.xaml.h"
#if __has_include("MyPage.g.cpp")
#include "MyPage.g.cpp"
#endif



/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace winrt
{

using namespace WinUI3App;

/*
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
*/

}



/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace winrt
{
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Media;
using namespace Microsoft::UI::Xaml::Media::Animation;
using namespace Microsoft::UI::Xaml::Navigation;
//using namespace Microsoft::UI::Xaml::Interop; // 추가된 네임스페이스
using namespace Windows::UI::Xaml::Interop;
}



/////////////////////////////////////////////////////////////////////////////
//===========================================================================
// 빈 페이지 항목 템플릿에 대한 설명은 https://go.microsoft.com/fwlink/?LinkId=234238에 나와 있습니다.
namespace winrt::WinUI3App::implementation
{

	MyPage::MyPage()
	{
		InitializeComponent();
	}

	void MyPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
	{
		myButton().Content(box_value(L"1Clicked"));
	}

}