require 'test_helper'

class ThreadingsControllerTest < ActionDispatch::IntegrationTest
  setup do
    @threading = threadings(:one)
  end

  test "should get index" do
    get threadings_url
    assert_response :success
  end

  test "should get new" do
    get new_threading_url
    assert_response :success
  end

  test "should create threading" do
    assert_difference('Threading.count') do
      post threadings_url, params: { threading: { id: @threading.id, value: @threading.value } }
    end

    assert_redirected_to threading_url(Threading.last)
  end

  test "should show threading" do
    get threading_url(@threading)
    assert_response :success
  end

  test "should get edit" do
    get edit_threading_url(@threading)
    assert_response :success
  end

  test "should update threading" do
    patch threading_url(@threading), params: { threading: { id: @threading.id, value: @threading.value } }
    assert_redirected_to threading_url(@threading)
  end

  test "should destroy threading" do
    assert_difference('Threading.count', -1) do
      delete threading_url(@threading)
    end

    assert_redirected_to threadings_url
  end
end
