﻿//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "Bedroom.xaml.h"

using namespace BlindDay;

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Platform;
using namespace Platform::Collections;
using namespace Concurrency;
using namespace Windows::Data::Xml::Dom;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Storage;
using namespace Windows::Storage::BulkAccess;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Streams;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Media::SpeechSynthesis;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409
//This is Mason Testing it out

MainPage::MainPage()
{
	InitializeComponent();

	//creating a new speech synthesizer object 
	this->synthesizer = ref new Windows::Media::SpeechSynthesis::SpeechSynthesizer();
}

//actual creation of the stream using the new voice synthesis stream
task<SpeechSynthesisStream ^> BlindDay::MainPage::GetSpeechStreamTask(String ^ text)
{
	task<SpeechSynthesisStream ^>markersStream;
	markersStream = create_task(this->synthesizer->SynthesizeTextToStreamAsync(text));
	return markersStream;
}

void BlindDay::MainPage::button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}

void BlindDay::MainPage::button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Bedroom::typeid);
}


//if media state changes to stop or pause, re-enable the speak button for audio control
void BlindDay::MainPage::media_CurrentStateChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	MediaElement ^element = (MediaElement ^)sender;

	if (element->CurrentState == MediaElementState::Stopped ||
		element->CurrentState == MediaElementState::Paused)
	{
		this->button->IsEnabled = true;
		this->button1->IsEnabled = true;
		this->button2->IsEnabled = true;
	}
}


void BlindDay::MainPage::button1_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "This is a button to start adventure! Click it to proceed!";

	try
	{
		auto speakTask = this->GetSpeechStreamTask(text);
		speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
		{
			// start this audio stream playing
			this->media->SetSource(speechStream, speechStream->ContentType);
			this->media->AutoPlay = true;
			this->media->Play();

		});
	}
	catch (Exception ^ex)
	{
		hr = ex->HResult;

	}
}


void BlindDay::MainPage::button2_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "That's an exit button! Click it to close the app";

	try
	{
		auto speakTask = this->GetSpeechStreamTask(text);
		speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
		{
			// start this audio stream playing
			this->media->SetSource(speechStream, speechStream->ContentType);
			this->media->AutoPlay = true;
			this->media->Play();

		});
	}
	catch (Exception ^ex)
	{
		hr = ex->HResult;

	}
}


void BlindDay::MainPage::button2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	App::Current->Exit();
}


void BlindDay::MainPage::button_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "Ok! So this is where the title of our game is located. It says \"A Blind Day\"";

	try
	{
		auto speakTask = this->GetSpeechStreamTask(text);
		speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
		{
			// start this audio stream playing
			this->media->SetSource(speechStream, speechStream->ContentType);
			this->media->AutoPlay = true;
			this->media->Play();

		});
	}
	catch (Exception ^ex)
	{
		hr = ex->HResult;

	}
}


void BlindDay::MainPage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "Welcome to our game \"A Blind Day\"! As you can see it has no graphics! It's done on purpose!"
                    " We simulate the senses of a blind person! Move the mouse around to discover elements!";

	try
	{
		auto speakTask = this->GetSpeechStreamTask(text);
		speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
		{
			// start this audio stream playing
			this->media->SetSource(speechStream, speechStream->ContentType);
			this->media->AutoPlay = true;
			this->media->Play();

		});
	}
	catch (Exception ^ex)
	{
		hr = ex->HResult;

	}
}
