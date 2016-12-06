/*
 * Copyright © 2015 ZTE and others.  All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v1.0 which accompanies this distribution,
 * and is available at http://www.eclipse.org/legal/epl-v10.html
 */
package com.highstreet.technologies.odl.app.spectrum.impl.meta;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import static com.highstreet.technologies.odl.app.spectrum.impl.meta.Pair.pair;

/**
 * Created by olinchy on 6/16/14 for MO_JAVA.
 */
public class DNWrapper implements Serializable, Comparable<DNWrapper>
{
    private final LinkedList<Pair<String, String>> lst = new LinkedList<Pair<String, String>>();
    private final ArrayList<String> seq = new ArrayList<String>(20);

    public DNWrapper(String dn)
    {
        if (dn != null)
        {
            dn = dn.replace("//", "/");
        }
        wrap(dn);
    }

    public static boolean is(String dnString)
    {
        return dnString != null && dnString.startsWith("/");
    }

    @Override
    public boolean equals(Object o)
    {
        if (this == o) return true;
        if (!(o instanceof DNWrapper)) return false;

        DNWrapper dnWrapper = (DNWrapper) o;

        return seq.equals(dnWrapper.seq);
    }

    @Override
    public int hashCode()
    {
        return seq.hashCode();
    }

    public String to(String keyword) throws Exception
    {
        int index = seq.indexOf(keyword);
        if (index == -1)
        {
            throw new Exception("non-valid key");
        }

        return to(index + 1);
    }

    public String type()
    {
        return lst.getLast().first();
    }

    public String parent()
    {
        return this.to(seq.size() - 2);
    }

    public String value(int index)
    {
        return seq.get(wrapIndex(index, seq));
    }

    public String to(int index)
    {
        StringBuilder builder = new StringBuilder(48);
        for (int i = 0; i <= wrapIndex(index, seq); i++)
        {
            builder.append(seq.get(i)).append("/");
        }
        String ret = builder.toString();

        ret = ret.replace("//", "/");

        if (ret.endsWith("/") && ret.length() > 1)
        {
            ret = ret.substring(0, ret.length() - 1);
        }
        return ret;
    }

    public boolean isSizeInOdd()
    {
        return lst.getLast().second().equals("");
    }

    public String value(String type)
    {
        int index = seq.indexOf(type);
        return value(index + 1);
    }

    public String append(String value)
    {
        if (isSizeInOdd())
        {
            this.lst.getLast().setSecond(value);
        } else
        {
            this.lst.add(pair(value, ""));
        }
        this.seq.add(value);

        return this.to(-1);
    }

    public int compareTo(DNWrapper that)
    {
        if (this.seq.size() != that.seq.size())
        {
            return new Integer(that.seq.size()).compareTo(this.seq.size());
        }

        for (int i = 0; i < seq.size(); i++)
        {
            String thisValue = seq.get(i);
            String thatValue = that.seq.get(i);
            int value = compare(thisValue, thatValue);
            if (value != 0)
                return value;
        }

        return 0;
    }

    private int compare(String thisValue, String thatValue)
    {
        char[] arr1 = thisValue.toCharArray();
        char[] arr2 = thatValue.toCharArray();

        int i = 0, j = 0;
        while (i < arr1.length && j < arr2.length)
        {
            if (Character.isDigit(arr1[i]) && Character.isDigit(arr2[j]))
            {
                String s1 = "", s2 = "";
                while (i < arr1.length && Character.isDigit(arr1[i]))
                {
                    s1 += arr1[i];
                    i++;
                }
                while (j < arr2.length && Character.isDigit(arr2[j]))
                {
                    s2 += arr2[j];
                    j++;
                }

                if (Integer.parseInt(s1) > Integer.parseInt(s2))
                {
                    return 1;
                }

                if (Integer.parseInt(s1) < Integer.parseInt(s2))
                {
                    return -1;
                }

            } else
            {
                if (arr1[i] > arr2[j])
                {
                    return 1;
                }

                if (arr1[i] < arr2[j])
                {
                    return -1;
                }
                i++;
                j++;

            }

        }

        if (arr1.length == arr2.length)
        {
            return 0;
        } else
        {
            return arr1.length > arr2.length ? 1 : -1;
        }
    }

    public boolean deeperThan(DNWrapper wrapper)
    {
        return this.lst.size() > wrapper.lst.size();
    }

    private int wrapIndex(int index, List<?> lst)
    {
        if (index < 0)
        {
            // from tail
            return lst.size() + index;
        }
        if (index >= 0 && index < lst.size() - 1)
        {
            // from head
            return index;
        }
        // out of index
        return lst.size() - 1;
    }

    private void wrap(String dn)
    {
        split(dn);

        toKey_Value();
    }

    private void toKey_Value()
    {
        ArrayList<String> keyAndValues = new ArrayList<String>();
        keyAndValues.add("Root");
        keyAndValues.addAll(seq);
        for (int i = 0; i < keyAndValues.size(); i += 2)
        {
            lst.add(
                    new Pair<String, String>(
                            keyAndValues.get(i),
                            i + 1 == keyAndValues.size() ? "" : keyAndValues.get(i + 1)));
        }
    }

    public String evenPos()
    {
        StringBuffer buf = new StringBuffer(256);
        int i = 0;
        for (Pair<String, String> one : lst)
        {
            if (i == 0)
            {
                i++;
            } else
            {
                buf.append("/").append(one.first());
            }
        }
        if (buf.length() == 0)
        {
            buf.append("/");
        }
        return buf.toString();
    }

    private void split(String dn)
    {
        seq.add("/");
        String temp = cutFirstAndLastSlash(dn);
        if (temp.contains("/"))
        {
            seq.addAll(Arrays.asList(temp.split("/")));
        } else if (!temp.equals(""))
        {
            seq.add(temp);
        }
    }

    private String cutFirstAndLastSlash(String dn)
    {
        if (dn == null || dn.isEmpty())
        {
            return "";
        }
        String temp = null;

        if (dn.startsWith("/"))
        {
            temp = dn.substring(1);
        }
        if (temp != null && temp.endsWith("/"))
        {
            temp = temp.substring(0, temp.length() - 1);
        }
        return temp;
    }

    public boolean isOffspringOf(DNWrapper wrapper)
    {
        if (wrapper == null || wrapper.to(-1).equals("/"))
        {
            return true;
        }
        return this.to(-1).startsWith(wrapper.to(-1) + "/");
    }

    @Override
    public String toString()
    {
        return seq.toString();
    }
}
