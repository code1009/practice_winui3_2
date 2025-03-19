//
// MainPage.xaml.cpp
// MainPage 클래스의 구현
//

#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
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
namespace winrt::WinUI3App::implementation
{

	MainPage::MainPage()
	{
		InitializeComponent();
	}

	void MainPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
	{
		myButton().Content(box_value(L"0Clicked"));
	}

}