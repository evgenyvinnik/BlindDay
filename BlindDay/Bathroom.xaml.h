//
// Bathroom_1.xaml.h
// Declaration of the Bathroom_1 class
//

#pragma once

#include "Bathroom.g.h"
using namespace Windows::Media::SpeechSynthesis;
using namespace Platform;

namespace BlindDay
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class Bathroom sealed
	{
	public:
		Bathroom();

	private:
		void media_CurrentStateChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		// this function will make the call to the speech synthesis engine, and determine
		// if it should use the SSML or Text implementation
		Concurrency::task<SpeechSynthesisStream ^> BlindDay::Bathroom::GetSpeechStreamTask(String ^ text);

		// private member
		Windows::Media::SpeechSynthesis::SpeechSynthesizer^ synthesizer;
		void button_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void button1_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void button2_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void button3_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void button4_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void button5_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void button6_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void button7_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button7_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Grid_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		//void button7__final_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

	};
}
