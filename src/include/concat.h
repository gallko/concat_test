#pragma once

#include <memory>

namespace test_concat {
    template<typename T>
    void mul_matrix(const T *m1, const T *m2, size_t l, size_t m, size_t n, T *result) {
        for (size_t l_i = 0; l_i < l; l_i++) {
            auto row_result = result + (l_i * n);
            for (size_t n_i = 0; n_i < n; n_i++) {
                auto row_m1 = m1 + (l_i * m);
                row_result[n_i] = 0;
                for (size_t m_i = 0; m_i < m; m_i++) {
                    row_result[n_i] += row_m1[m_i] * (m2 + m_i * n)[n_i];
                }
            }
        }
    }

    template<typename T>
    void generate_unit_matrix(T *m1, const size_t m) {
        for (size_t i = 0, u = 0; i < m * m; i++) {
            if (i != u) {
                m1[i] = 0;
            } else {
                m1[i] = 1;
                u += m + 1;
            }
        }
    }

    template<typename T>
    void concat_vectors(const T *m1, size_t s1, const T *m2, size_t s2, T *result) {
        auto max_s = std::max(s1, s2);
        std::unique_ptr<T[]> unit_matrix(new int[max_s * max_s]);

        generate_unit_matrix(unit_matrix.get(), s1);
        mul_matrix(m1, unit_matrix.get(), 1, s1, s1, result);

        generate_unit_matrix(unit_matrix.get(), s2);
        mul_matrix(m2, unit_matrix.get(), 1, s2, s2, result + s1);
    }
}