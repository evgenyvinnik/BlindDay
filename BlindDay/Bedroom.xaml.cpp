//
// Bedroom.xaml.cpp
// Implementation of the Bedroom class
//

#include "pch.h"
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

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

int leftslipper = 0;
int rightslipper = 0;
int tshirt = 0;
int pants = 0;

Bedroom::Bedroom()
{
	InitializeComponent();

	//creating a new speech synthesizer object 
	this->synthesizer = ref new Windows::Media::SpeechSynthesis::SpeechSynthesizer();
}

//actual creation of the stream using the new voice synthesis stream
task<SpeechSynthesisStream ^> BlindDay::Bedroom::GetSpeechStreamTask(String ^ text)
{
	task<SpeechSynthesisStream ^>markersStream;
	markersStream = create_task(this->synthesizer->SynthesizeTextToStreamAsync(text));
	return markersStream;
}

//if media state changes to stop or pause, re-enable the speak button for audio control
void BlindDay::Bedroom::media_CurrentStateChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	MediaElement ^element = (MediaElement ^)sender;

	if (element->CurrentState == MediaElementState::Stopped ||
		element->CurrentState == MediaElementState::Paused)
	{
		//this->btnSpeak->IsEnabled = true;
	}
}

void BlindDay::Bedroom::button_PointerEntered_1(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "My bed is such a mess";

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


void BlindDay::Bedroom::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "Huh! I can't see a thing! Jeez! What happened to me? Oh, right! Doctor said something about temporary blindness after lasik surgery!";

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


void BlindDay::Bedroom::button1_PointerEntered_1(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "This is something hard. This must be my wall";

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


void BlindDay::Bedroom::button2_PointerEntered_1(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (rightslipper == 0 && leftslipper == 0 && tshirt == 0 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left slipper, right slipper, t-shirt, and pants.";

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

	else if (rightslipper == 1 && leftslipper == 0 && tshirt == 0 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left slipper, t-shirt, and pants.";

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

	else if (rightslipper == 0 && leftslipper == 1 && tshirt == 0 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my right slipper, t-shirt, and pants.";

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

	else if (rightslipper == 0 && leftslipper == 0 && tshirt == 1 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left slipper, right slipper, and pants.";

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

	else if (rightslipper == 0 && leftslipper == 0 && tshirt == 0 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left slipper, right slipper, and t-shirt";

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

	else if (rightslipper == 1 && leftslipper == 1 && tshirt == 0 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my t-shirt and pants.";

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
	else if (rightslipper == 0 && leftslipper == 1 && tshirt == 1 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my right slipper and pants.";

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
	else if (rightslipper == 0 && leftslipper == 0 && tshirt == 1 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left slipper and right slipper.";

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

	else if (rightslipper == 1 && leftslipper == 0 && tshirt == 0 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left slipper and pants.";

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

	else if (rightslipper == 1 && leftslipper == 1 && tshirt == 1 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my pants.";

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

	else if (rightslipper == 0 && leftslipper == 1 && tshirt == 1 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my right slipper.";

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

	else if (rightslipper == 1 && leftslipper == 0 && tshirt == 1 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left slipper.";

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

	else if (rightslipper == 1 && leftslipper == 1 && tshirt == 0 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my t-shirt.";

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

	else
	{
		//this is where we will nagivate to the washroom
	}
}


void BlindDay::Bedroom::button3_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (rightslipper == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Ahh. There is my right slipper.";

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
}


void BlindDay::Bedroom::button4_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (leftslipper == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Ahh. There is my left slipper.";

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
}


void BlindDay::Bedroom::button5_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (tshirt == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Ahh. There is my t-shirt.";

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
}


void BlindDay::Bedroom::button6_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Ahh. There is my pants.";

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
}

void BlindDay::Bedroom::button7_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "This is where my window is I think.";

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


void BlindDay::Bedroom::button3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (rightslipper == 0)
	{

		HRESULT hr = S_OK;
		String^ text = "I'll put on my right slipper.";

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

		rightslipper++;
	}
}


void BlindDay::Bedroom::button4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (leftslipper == 0)
	{

		HRESULT hr = S_OK;
		String^ text = "I'll put on my left slipper.";

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

		leftslipper++;
	}
}


void BlindDay::Bedroom::button5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (tshirt == 0)
	{

		HRESULT hr = S_OK;
		String^ text = "I'll put on my tshirt.";

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

		tshirt++;
	}
}


void BlindDay::Bedroom::button6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (pants == 0)
	{

		HRESULT hr = S_OK;
		String^ text = "I'll put on my pants.";

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

		pants++;
	}
}
