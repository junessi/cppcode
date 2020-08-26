#include <type_traits>

namespace cppcode { namespace common {
    namespace is_range_based_helper {
        template <typename...> using void_t = void;

        // has begin()
        template <typename T, typename = void>
        struct has_begin : std::false_type {};

        template <typename T>
        struct has_begin<T, void_t<decltype(std::declval<T>().begin())>> : std::true_type {};

        // has end()
        template <typename T, typename = void>
        struct has_end : std::false_type {};

        template <typename T>
        struct has_end<T, void_t<decltype(std::declval<T>().end())>> : std::true_type {};

        // has iterator
        template <typename T, typename = void>
        struct has_iterator : std::false_type {};

        template <typename T>
        struct has_iterator<T, void_t<typename T::iterator>>
        {
            typedef decltype(*(std::declval<typename T::iterator>())) derefType;
            static const bool value = std::is_same<T, typename std::remove_cv<typename std::remove_reference<derefType>::type>::type>::value;
        };

        template <typename T>
        const bool has_iterator<T, void_t<typename T::iterator>>::value;

        // has first
        template <typename T, typename = void>
        struct has_first : std::false_type {};

        template <typename T>
        struct has_first<T, void_t<decltype(T::first)>> : std::true_type {};

        // has second
        template <typename T, typename = void>
        struct has_second : std::false_type {};

        template <typename T>
        struct has_second<T, void_t<decltype(T::second)>> : std::true_type {};

        // has pre-incrementable iterator
        template <typename T, typename = void>
        struct has_pre_inc_iterator : std::false_type {};

        template <typename T>
        struct has_pre_inc_iterator<T, void_t<decltype(++(std::declval<typename T::iterator>()))>> : std::true_type {};

    }

    // is_range_based
    template <typename T>
    struct is_range_based
    {
        static const bool value = is_range_based_helper::has_begin<T>::value &&
                                  is_range_based_helper::has_end<T>::value &&
                                  is_range_based_helper::has_iterator<T>::value &&
                                  is_range_based_helper::has_pre_inc_iterator<T>::value;
    };

    template <typename T>
    const bool is_range_based<T>::value;
}}
