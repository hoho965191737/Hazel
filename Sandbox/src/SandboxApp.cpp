#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>

#include "GameLayer.h"



class Sandbox: public Hazel::Application
{
public:
	Sandbox() {
		PushLayer(new GameLayer());
	}
	~Sandbox() {

	}

private:

};


Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}