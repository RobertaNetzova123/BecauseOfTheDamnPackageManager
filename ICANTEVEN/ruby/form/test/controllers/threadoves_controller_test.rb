require 'test_helper'

class ThreadovesControllerTest < ActionDispatch::IntegrationTest
  setup do
    @threadofe = threadoves(:one)
  end

  test "should get index" do
    get threadoves_url
    assert_response :success
  end

  test "should get new" do
    get new_threadofe_url
    assert_response :success
  end

  test "should create threadofe" do
    assert_difference('Threadove.count') do
      post threadoves_url, params: { threadofe: { id: @threadofe.id, value: @threadofe.value } }
    end

    assert_redirected_to threadofe_url(Threadove.last)
  end

  test "should show threadofe" do
    get threadofe_url(@threadofe)
    assert_response :success
  end

  test "should get edit" do
    get edit_threadofe_url(@threadofe)
    assert_response :success
  end

  test "should update threadofe" do
    patch threadofe_url(@threadofe), params: { threadofe: { id: @threadofe.id, value: @threadofe.value } }
    assert_redirected_to threadofe_url(@threadofe)
  end

  test "should destroy threadofe" do
    assert_difference('Threadove.count', -1) do
      delete threadofe_url(@threadofe)
    end

    assert_redirected_to threadoves_url
  end
end
