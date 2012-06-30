/*
SMAK - The Super Model Army Knife
Copyright (C) 2012, Lunar Workshop, Inc

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#ifndef SMAK_SCENETREE_H
#define SMAK_SCENETREE_H

#include <glgui/movablepanel.h>

#include "smakwindow_ui.h"

class CSceneTreePanel : public glgui::CMovablePanel
{
	DECLARE_CLASS(CSceneTreePanel, glgui::CMovablePanel);

public:
									CSceneTreePanel(class CConversionScene* pScene);
									~CSceneTreePanel();

public:
	void							Layout();
	void							Paint(float x, float y, float w, float h);

	void							UpdateTree();
	void							AddAllToTree();
	void							AddNodeToTree(glgui::CTreeNode* pTreeNode, class CConversionSceneNode* pNode);

	void							OpenMaterialEditor(class CConversionMaterial* pMaterial);
	void							CloseMaterialEditor();

	size_t							GetLastSelectedMaterial() { return m_iLastSelectedMaterial; }

	EVENT_CALLBACK(CSceneTreePanel, Selected);

	static void						Open(class CConversionScene* pScene);
	static CSceneTreePanel*			Get();

public:
	class CConversionScene*			m_pScene;

	glgui::CControl<glgui::CTree>	m_hTree;

	glgui::CControl<CBaseControl>	m_hMaterialEditor;

	size_t							m_iLastSelectedMaterial;

	static glgui::CControl<CSceneTreePanel>		s_hSceneTreePanel;
};

void OpenMaterialEditor(class CConversionMaterial* pMaterial, const tstring& sArgs);

class CMaterialEditor : public glgui::CMovablePanel
{
	DECLARE_CLASS(CMaterialEditor, glgui::CMovablePanel);

public:
									CMaterialEditor(CConversionMaterial* pMaterial, glgui::CControl<CSceneTreePanel> hSceneTree);

public:
	void							SetupSelector(glgui::CScrollSelector<float>* pSelector, float flMaxValue);

	void							Layout();

	EVENT_CALLBACK(CMaterialEditor, ChooseDiffuse);
	EVENT_CALLBACK(CMaterialEditor, ChooseNormal);
	EVENT_CALLBACK(CMaterialEditor, OpenDiffuse);
	EVENT_CALLBACK(CMaterialEditor, OpenNormal);
	EVENT_CALLBACK(CMaterialEditor, RemoveDiffuse);
	EVENT_CALLBACK(CMaterialEditor, RemoveNormal);
	EVENT_CALLBACK(CMaterialEditor, SetAmbientRed);
	EVENT_CALLBACK(CMaterialEditor, SetAmbientGreen);
	EVENT_CALLBACK(CMaterialEditor, SetAmbientBlue);
	EVENT_CALLBACK(CMaterialEditor, SetDiffuseRed);
	EVENT_CALLBACK(CMaterialEditor, SetDiffuseGreen);
	EVENT_CALLBACK(CMaterialEditor, SetDiffuseBlue);
	EVENT_CALLBACK(CMaterialEditor, SetSpecularRed);
	EVENT_CALLBACK(CMaterialEditor, SetSpecularGreen);
	EVENT_CALLBACK(CMaterialEditor, SetSpecularBlue);
	EVENT_CALLBACK(CMaterialEditor, SetEmissiveRed);
	EVENT_CALLBACK(CMaterialEditor, SetEmissiveGreen);
	EVENT_CALLBACK(CMaterialEditor, SetEmissiveBlue);
	EVENT_CALLBACK(CMaterialEditor, SetShininess);

protected:
	CConversionMaterial*			m_pMaterial;
	glgui::CControl<CSceneTreePanel>	m_hSceneTree;
	CConversionScene*				m_pScene;
	size_t							m_iMaterial;

	glgui::CControl<glgui::CLabel>					m_hDiffuseLabel;
	glgui::CControl<glgui::CButton>					m_hDiffuseFile;
	glgui::CControl<glgui::CButton>					m_hDiffuseRemove;

	glgui::CControl<glgui::CLabel>					m_hNormalLabel;
	glgui::CControl<glgui::CButton>					m_hNormalFile;
	glgui::CControl<glgui::CButton>					m_hNormalRemove;

	glgui::CControl<glgui::CLabel>					m_hAmbientLabel;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hAmbientRedSelector;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hAmbientGreenSelector;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hAmbientBlueSelector;

	glgui::CControl<glgui::CLabel>					m_hDiffuseSelectorLabel;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hDiffuseRedSelector;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hDiffuseGreenSelector;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hDiffuseBlueSelector;

	glgui::CControl<glgui::CLabel>					m_hSpecularLabel;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hSpecularRedSelector;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hSpecularGreenSelector;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hSpecularBlueSelector;

	glgui::CControl<glgui::CLabel>					m_hEmissiveLabel;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hEmissiveRedSelector;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hEmissiveGreenSelector;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hEmissiveBlueSelector;

	glgui::CControl<glgui::CLabel>					m_hShininessLabel;
	glgui::CControl<glgui::CScrollSelector<float>>	m_hShininessSelector;
};

inline CSceneTreePanel* SceneTree()
{
	return CSceneTreePanel::Get();
}

#endif