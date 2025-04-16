//
// ControlPage.xaml.cpp
// ControlPage 클래스의 구현
//

#include "pch.h"
#include "ControlPage.xaml.h"
#if __has_include("ControlPage.g.cpp")
#include "ControlPage.g.cpp"
#endif
#include <random>


/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace winrt
{

using namespace WinUI3App;


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

using namespace Windows::UI::Xaml::Interop;
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace winrt::WinUI3App::implementation
{

ControlPage::ControlPage()
{
	InitializeComponent();
}

void ControlPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
{
	myButton().Content(box_value(L"1Clicked"));
}



void ControlPage::TextBlock_Click(IInspectable const&, RoutedEventArgs const&)
{
	/*
	winrt::Microsoft::UI::Xaml::Media::Brush myBrush =
		winrt::Microsoft::UI::Xaml::Media::SolidColorBrush{ Windows::UI::Colors::Red() };

	myPath().Fill( myBrush );
	*/

	// xaml: Path
	// PathGeometry 생성
	auto pathGeometry = winrt::Microsoft::UI::Xaml::Media::PathGeometry{};
	auto pathFigure = winrt::Microsoft::UI::Xaml::Media::PathFigure{};
	pathFigure.StartPoint({ 0, 0 });

	// PathSegment 추가
	auto lineSegment1 = winrt::Microsoft::UI::Xaml::Media::LineSegment{};
	lineSegment1.Point({ 100, 0 });
	pathFigure.Segments().Append(lineSegment1);

	auto lineSegment2 = winrt::Microsoft::UI::Xaml::Media::LineSegment{};
	lineSegment2.Point({ 100, 100 });
	pathFigure.Segments().Append(lineSegment2);

	auto lineSegment3 = winrt::Microsoft::UI::Xaml::Media::LineSegment{};
	lineSegment3.Point({ 0, 100 });
	pathFigure.Segments().Append(lineSegment3);

	// 닫힌 도형으로 설정
	pathFigure.IsClosed(true);

	// PathFigure를 PathGeometry에 추가
	pathGeometry.Figures().Append(pathFigure);


	myPath().Data(pathGeometry);


	std::thread([this]()
		{
			// 백그라운드 작업 (예: 데이터 처리, 계산 등)
			std::this_thread::sleep_for(std::chrono::seconds(2)); // 예제: 2초 대기

			// UI 스레드에서 Path의 색 변경
			DispatcherQueue().TryEnqueue([this]()
				{
					/*
					// Path의 Fill 속성을 빨간색으로 설정
					winrt::Microsoft::UI::Xaml::Media::Brush myBrush =
						winrt::Microsoft::UI::Xaml::Media::SolidColorBrush{ Windows::UI::Colors::Red() };
						*/

					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_int_distribution<> dis(0, 255);

					uint8_t red = static_cast<uint8_t>(dis(gen));
					uint8_t green = static_cast<uint8_t>(dis(gen));
					uint8_t blue = static_cast<uint8_t>(dis(gen));
					winrt::Windows::UI::Color randomColor = { 255, red, green, blue }; // A(투명도)는 255로 설정
					winrt::Microsoft::UI::Xaml::Media::Brush myBrush =
						winrt::Microsoft::UI::Xaml::Media::SolidColorBrush{ randomColor };
					myPath().Fill(myBrush);
				});
		}).detach(); // 스레드를 분리하여 실행
}


}