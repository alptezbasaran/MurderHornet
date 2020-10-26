#include "MurderHornetApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MurderHornetApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

MurderHornetApp::MurderHornetApp(InputParameters parameters) : MooseApp(parameters)
{
  MurderHornetApp::registerAll(_factory, _action_factory, _syntax);
}

MurderHornetApp::~MurderHornetApp() {}

void
MurderHornetApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"MurderHornetApp"});
  Registry::registerActionsTo(af, {"MurderHornetApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MurderHornetApp::registerApps()
{
  registerApp(MurderHornetApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MurderHornetApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MurderHornetApp::registerAll(f, af, s);
}
extern "C" void
MurderHornetApp__registerApps()
{
  MurderHornetApp::registerApps();
}
