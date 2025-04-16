//
// ControlPage.xaml.h
// Dsafeitemname$ 클래스의 선언
//

#pragma once

#include "ControlPage.g.h"

namespace winrt::WinUI3App::implementation
{
/// <summary>
/// 자체적으로 사용하거나 프레임 내에서 탐색할 수 있는 빈 페이지입니다.
/// </summary>
struct ControlPage : ControlPageT<ControlPage>
{
public:
	ControlPage();

public:
	void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
	void TextBlock_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
};
}


namespace winrt::WinUI3App::factory_implementation
{
struct ControlPage : ControlPageT<ControlPage, implementation::ControlPage>
{
};
}
