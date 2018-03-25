require 'test_helper'

class CinemaFilmsControllerTest < ActionDispatch::IntegrationTest
  setup do
    @cinema_film = cinema_films(:one)
  end

  test "should get index" do
    get cinema_films_url
    assert_response :success
  end

  test "should get new" do
    get new_cinema_film_url
    assert_response :success
  end

  test "should create cinema_film" do
    assert_difference('CinemaFilm.count') do
      post cinema_films_url, params: { cinema_film: {  } }
    end

    assert_redirected_to cinema_film_url(CinemaFilm.last)
  end

  test "should show cinema_film" do
    get cinema_film_url(@cinema_film)
    assert_response :success
  end

  test "should get edit" do
    get edit_cinema_film_url(@cinema_film)
    assert_response :success
  end

  test "should update cinema_film" do
    patch cinema_film_url(@cinema_film), params: { cinema_film: {  } }
    assert_redirected_to cinema_film_url(@cinema_film)
  end

  test "should destroy cinema_film" do
    assert_difference('CinemaFilm.count', -1) do
      delete cinema_film_url(@cinema_film)
    end

    assert_redirected_to cinema_films_url
  end
end
