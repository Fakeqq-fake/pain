data class Movie(
    val title: String,
    val genre: String,
    val year: Int,
    val rating: Double,
    val durationMinutes: Int,
    val isAvailable: Boolean
)

data class MovieCard(
    val title: String,
    val info: String
)

fun main() {
    val movies = listOf(
        Movie("The Matrix", "Sci-Fi", 1999, 8.7, 136, true),
        Movie("Inception", "Sci-Fi", 2010, 8.8, 148, true),
        Movie("Joker", "Drama", 2019, 8.4, 122, false),
        Movie("Deadpool", "Action", 2016, 8.0, 108, true),
        Movie("Toy Story", "Animation", 1995, 8.3, 81, true),
        Movie("Get Out", "Horror", 2017, 7.7, 104, false),
        Movie("Parasite", "Drama", 2019, 8.6, 132, true),
        Movie("Spider-Man: No Way Home", "Action", 2021, 8.2, 148, true),
        Movie("Minions", "Animation", 2015, 5.5, 91, true),
        Movie("A Quiet Place", "Horror", 2018, 7.5, 90, false)
    )

    println("=== 3. Базовая фильтрация ===")
    println("Доступные фильмы:")
    movies.filter { it.isAvailable }.forEach { println(it.title) }

    println("\nФильмы с рейтингом выше 8.0:")
    movies.filter { it.rating > 8.0 }.forEach { println("${it.title} (${it.rating})") }

    println("\nФильмы после 2020:")
    movies.filter { it.year > 2020 }.forEach { println("${it.title} (${it.year})") }

    println("\nКороткие фильмы (<100 мин):")
    movies.filter { it.durationMinutes < 100 }.forEach { println("${it.title} (${it.durationMinutes} мин)") }

    println("\nФильмы жанра Action:")
    movies.filter { it.genre == "Action" }.forEach { println(it.title) }

    println("\n=== 4. Сортировка ===")
    println("Фильмы по году выпуска:")
    movies.sortedBy { it.year }.forEach { println("${it.title} (${it.year})") }

    println("\nПо рейтингу (топ вниз):")
    movies.sortedByDescending { it.rating }.forEach { println("${it.title} (${it.rating})") }

    println("\nПо длительности:")
    movies.sortedBy { it.durationMinutes }.forEach { println("${it.title} (${it.durationMinutes} мин)") }

    println("\nТоп-3 фильма по рейтингу:")
    movies.sortedByDescending { it.rating }.take(3).forEach { println("${it.title} (${it.rating})") }

    println("\n=== 5. Поиск фильма ===")
    val searchTitle = "Joker"
    val foundMovie = movies.find { it.title == searchTitle }
    if (foundMovie != null) {
        println("Фильм найден: ${foundMovie.title}, рейтинг: ${foundMovie.rating}")
    } else {
        println("Фильм не найден")
    }

    println("\n=== 6. Проверки any/all ===")
    println("Есть ли фильм жанра Horror: ${movies.any { it.genre == "Horror" }}")
    println("Есть ли фильм с рейтингом <5.0: ${movies.any { it.rating < 5.0 }}")
    println("Есть ли недоступный фильм: ${movies.any { !it.isAvailable }}")

    println("Все фильмы с рейтингом >0: ${movies.all { it.rating > 0 }}")
    println("Все фильмы после 1980: ${movies.all { it.year > 1980 }}")
    println("Все фильмы доступны: ${movies.all { it.isAvailable }}")

    println("\n=== 7. Подсчёты count ===")
    println("Количество доступных фильмов: ${movies.count { it.isAvailable }}")
    println("С рейтингом >8.0: ${movies.count { it.rating > 8.0 }}")
    println("После 2020: ${movies.count { it.year > 2020 }}")

    val genreCounts = movies.groupBy { it.genre }.mapValues { it.value.size }
    println("\nКоличество фильмов по жанрам:")
    genreCounts.forEach { (genre, count) ->
        println("$genre: $count")
    }

    println("\n=== 8. Группировка groupBy ===")
    println("Группировка по жанрам:")
    val groupedByGenre = movies.groupBy { it.genre }
    groupedByGenre.forEach { (genre, movieList) ->
        println("Жанр: $genre")
        println("Количество фильмов: ${movieList.size}")
        println("Фильмы: ${movieList.joinToString { it.title }}")
        println()
    }

    println("Группировка по году:")
    val groupedByYear = movies.groupBy { it.year }
    groupedByYear.forEach { (year, movieList) ->
        println("Год: $year, фильмов: ${movieList.size}")
    }

    println("\nГруппировка по доступности:")
    val groupedByAvailability = movies.groupBy { it.isAvailable }
    groupedByAvailability.forEach { (isAvailable, movieList) ->
        val status = if (isAvailable) "доступны" else "недоступны"
        println("Фильмы $status: ${movieList.joinToString { it.title }}")
    }

    println("\n=== 9. Преобразование map ===")
    val movieCards = movies.map { movie ->
        MovieCard(
            title = movie.title,
            info = "Жанр: ${movie.genre}, рейтинг: ${movie.rating}, год: ${movie.year}"
        )
    }
    movieCards.forEach { card -> println("${card.title}: ${card.info}") }

    println("\n=== 10. Цепочка обработки ===")
    val recommendedTitles = movies
        .filter { it.isAvailable }
        .filter { it.rating > 7.5 }
        .sortedByDescending { it.rating }
        .map { it.title }
    println("Рекомендуемые названия: $recommendedTitles")

    println("\n=== 11. Собственная функция высшего порядка (filterMovies) ===")
    fun filterMovies(
        movies: List<Movie>,
        condition: (Movie) -> Boolean
    ): List<Movie> {
        return movies.filter(condition)
    }

    val availableMovies = filterMovies(movies) { it.isAvailable }
    val comedyMovies = filterMovies(movies) { it.genre == "Comedy" }
    val highRatingMovies = filterMovies(movies) { it.rating > 8.5 }
    val recentMovies = filterMovies(movies) { it.year > 2020 }
    val longMovies = filterMovies(movies) { it.durationMinutes > 120 }

    println("Доступных: ${availableMovies.size}")
    println("Комедий: ${comedyMovies.size}")
    println("Рейтинг >8.5: ${highRatingMovies.size}")
    println("После 2020: ${recentMovies.size}")
    println("Длиной >120 мин: ${longMovies.size}")

        println("\n=== 12. Собственная функция обработки рейтинга (processRating) ===")
    fun processRating(
        rating: Double,
        operation: (Double) -> Double
    ): Double {
        return operation(rating)
    }

    val increasedRating = processRating(8.5) { it + 0.2 }
    println("Рейтинг после увеличения: $increasedRating")

    val decreasedRating = processRating(8.5) { it - 0.5 }
    println("Рейтинг после уменьшения: $decreasedRating")

    val fivePointRating = processRating(8.5) { it / 2 }
    println("Рейтинг в 5-балльной системе: $fivePointRating")

    println("\n=== 13. Задание повышенной сложности (analyzeMovies) ===")
    fun analyzeMovies(
        movies: List<Movie>,
        filterCondition: (Movie) -> Boolean,
        sortCondition: (Movie) -> Double
    ): List<Movie> {
        return movies
            .filter(filterCondition)
            .sortedByDescending(sortCondition)
    }

    val availableSortedByRating = analyzeMovies(movies,
        { it.isAvailable },
        { it.rating }
    )
    println("Доступные фильмы по рейтингу:")
    availableSortedByRating.forEach { println("${it.title} (${it.rating})") }

    val recentSortedByRating = analyzeMovies(movies,
        { it.year > 2020 },
        { it.rating }
    )
    println("
Фильмы после 2020 по рейтингу:")
    recentSortedByRating.forEach { println("${it.title} (${it.rating})") }

    val shortSortedByDuration = analyzeMovies(movies,
        { it.durationMinutes < 100 },
        { it.durationMinutes.toDouble() }
    )
    println("
Короткие фильмы (<100 мин) по длительности:")
    shortSortedByDuration.forEach { println("${it.title} (${it.durationMinutes} мин)") }

    println("\n=== 14. Дополнительное творческое задание (система рекомендаций) ===")

    val recommendedMovies = movies
        .filter { it.isAvailable }
        .filter { it.rating > 7.5 }
        .filter { it.durationMinutes < 140 }
        .filter { it.genre != "Horror" }

    println("Список рекомендованных фильмов:")
    if (recommendedMovies.isEmpty()) {
        println("Рекомендаций нет")
    } else {
        recommendedMovies.forEach { movie ->
            println("Рекомендуем: ${movie.title} — рейтинг ${movie.rating}")
        }
    }
}
