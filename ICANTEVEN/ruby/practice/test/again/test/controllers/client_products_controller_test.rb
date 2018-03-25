require 'test_helper'

class ClientProductsControllerTest < ActionDispatch::IntegrationTest
  setup do
    @client_product = client_products(:one)
  end

  test "should get index" do
    get client_products_url
    assert_response :success
  end

  test "should get new" do
    get new_client_product_url
    assert_response :success
  end

  test "should create client_product" do
    assert_difference('ClientProduct.count') do
      post client_products_url, params: { client_product: { client_id: @client_product.client_id, product_id: @client_product.product_id } }
    end

    assert_redirected_to client_product_url(ClientProduct.last)
  end

  test "should show client_product" do
    get client_product_url(@client_product)
    assert_response :success
  end

  test "should get edit" do
    get edit_client_product_url(@client_product)
    assert_response :success
  end

  test "should update client_product" do
    patch client_product_url(@client_product), params: { client_product: { client_id: @client_product.client_id, product_id: @client_product.product_id } }
    assert_redirected_to client_product_url(@client_product)
  end

  test "should destroy client_product" do
    assert_difference('ClientProduct.count', -1) do
      delete client_product_url(@client_product)
    end

    assert_redirected_to client_products_url
  end
end
