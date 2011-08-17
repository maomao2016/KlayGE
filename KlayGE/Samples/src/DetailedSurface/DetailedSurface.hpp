#ifndef _DETAILEDSURFACE_HPP
#define _DETAILEDSURFACE_HPP

#include <KlayGE/App3D.hpp>
#include <KlayGE/Font.hpp>
#include <KlayGE/CameraController.hpp>
#include <KlayGE/UI.hpp>

class DetailedSurfaceApp : public KlayGE::App3DFramework
{
public:
	DetailedSurfaceApp();

	bool ConfirmDevice() const;

private:
	void InitObjects();
	void OnResize(KlayGE::uint32_t width, KlayGE::uint32_t height);

	void DoUpdateOverlay();
	KlayGE::uint32_t DoUpdate(KlayGE::uint32_t pass);

	void InputHandler(KlayGE::InputEngine const & sender, KlayGE::InputAction const & action);
	void ScaleChangedHandler(KlayGE::UISlider const & sender);
	void BiasChangedHandler(KlayGE::UISlider const & sender);
	void DetailTypeChangedHandler(KlayGE::UIComboBox const & sender);
	void CtrlCameraHandler(KlayGE::UICheckBox const & sender);

	KlayGE::FontPtr font_;
	KlayGE::SceneObjectPtr polygon_;

	KlayGE::FirstPersonCameraController fpcController_;

	KlayGE::SceneObjectPtr light_proxy_;
	KlayGE::LightSourcePtr light_;

	KlayGE::JudaTexturePtr juda_tex_;

	KlayGE::UIDialogPtr dialog_;
	float parallax_scale_;
	float parallax_bias_;

	int id_scale_static_;
	int id_scale_slider_;
	int id_bias_static_;
	int id_bias_slider_;
	int id_detail_type_static_;
	int id_detail_type_combo_;
	int id_ctrl_camera_;

	int loading_percentage_;
};

#endif		// _DETAILEDSURFACE_HPP