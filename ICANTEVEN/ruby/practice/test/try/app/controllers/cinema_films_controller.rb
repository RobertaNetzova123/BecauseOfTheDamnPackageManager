class CinemaFilmsController < ApplicationController
  before_action :set_cinema_film, only: [:show, :edit, :update, :destroy]

  # GET /cinema_films
  # GET /cinema_films.json
  def index
    @cinema_films = CinemaFilm.all
  end

  # GET /cinema_films/1
  # GET /cinema_films/1.json
  def show
  end

  # GET /cinema_films/new
  def new
    @cinema_film = CinemaFilm.new
  end

  # GET /cinema_films/1/edit
  def edit
  end

  # POST /cinema_films
  # POST /cinema_films.json
  def create
    @cinema_film = CinemaFilm.new(cinema_film_params)

    respond_to do |format|
      if @cinema_film.save
        format.html { redirect_to @cinema_film, notice: 'Cinema film was successfully created.' }
        format.json { render :show, status: :created, location: @cinema_film }
      else
        format.html { render :new }
        format.json { render json: @cinema_film.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /cinema_films/1
  # PATCH/PUT /cinema_films/1.json
  def update
    respond_to do |format|
      if @cinema_film.update(cinema_film_params)
        format.html { redirect_to @cinema_film, notice: 'Cinema film was successfully updated.' }
        format.json { render :show, status: :ok, location: @cinema_film }
      else
        format.html { render :edit }
        format.json { render json: @cinema_film.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /cinema_films/1
  # DELETE /cinema_films/1.json
  def destroy
    @cinema_film.destroy
    respond_to do |format|
      format.html { redirect_to cinema_films_url, notice: 'Cinema film was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_cinema_film
      @cinema_film = CinemaFilm.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def cinema_film_params
      params.fetch(:cinema_film, {})
    end
end
