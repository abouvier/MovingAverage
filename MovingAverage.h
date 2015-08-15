/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MovingAverage.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvier <abouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 18:01:48 by abouvier          #+#    #+#             */
/*   Updated: 2015/08/15 21:58:07 by abouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H

#include "CircularBuffer.h"

template <typename T, size_t Size>
class MovingAverage
{
public:
	typedef T value_type;
	typedef CircularBuffer<T,Size> container_type;
	typedef typename container_type::reference reference;
	typedef typename container_type::const_reference const_reference;
	typedef typename container_type::size_type size_type;

private:
	container_type m_buffer;
	value_type m_sum;

public:
	MovingAverage() : m_sum(0) {}

	void push(const_reference value)
	{
		if (m_buffer.full())
			m_sum -= m_buffer.front();
		m_buffer.push_back(value);
		m_sum += value;
	}

	reference back()
	{
		return m_buffer.back();
	}

	const_reference back() const
	{
		return m_buffer.back();
	}

	size_type size() const
	{
		return m_buffer.size();
	}

	value_type sum() const
	{
		return m_sum;
	}

	value_type average() const
	{
		return sum() / m_buffer.size();
	}
};

#endif
